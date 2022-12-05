#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <regex>

int main() {
	std::ifstream fs{"input.txt"};

	std::vector<std::deque<std::string>> stacks_1{};
	std::vector<std::deque<std::string>> stacks_2{};
	if(!fs.is_open()) return 1;
	std::sregex_token_iterator rend;
	std::regex discrim{"[ |\\[]([A-Z]| )[ |\\]](\\s|$)"};
	std::regex instruction{"\\w+ ([0-9]+) \\w+ ([0-9]+) \\w+ ([0-9]+)"};

	int stage = 0;

	int qty, from, to;


	std::string buff;
	while(std::getline(fs,buff)) {
		int lineMatches = 1;
		switch(stage) {
			case 0: { // read in boxes	
				std::sregex_token_iterator a{buff.begin(),buff.end(),discrim,1};
				if(a==rend) lineMatches = 0;
				int idx = 0;
				while(a!=rend) {
					if(idx == stacks_1.size()) {
						stacks_1.push_back(std::deque<std::string>{});
						stacks_2.push_back(std::deque<std::string>{});
					}
					if(*a != " ") {
						stacks_1[idx].push_front(*a);
						stacks_2[idx].push_front(*a);
					}
					a++;
					idx++;
				}
				break;
			}

			case 1: {
				std::smatch matches;
				if(!std::regex_search(buff,matches,instruction)) break;
				
				qty = std::stoi(matches[1]);
				from = std::stoi(matches[2]) - 1;
				to = std::stoi(matches[3]) - 1;

				stacks_2[to].insert(stacks_2[to].end(),stacks_2[from].end()-qty,stacks_2[from].end());
				stacks_2[from].erase(stacks_2[from].end()-qty,stacks_2[from].end());

				while(qty != 0 && stacks_1[from].size() != 0) {
					stacks_1[to].push_back({stacks_1[from].back()});
					stacks_1[from].pop_back();
					qty--;
				}

				break;
			}

			default: {
				break;
			}
				


		}
		if(!lineMatches) stage++;
	}
	std::cout << "Part 1: ";
	for(const auto & v : stacks_1) {
		std::cout << v.back();
	}
	std::cout << std::endl;
	std::cout << "Part 2: ";
	for(const auto & v: stacks_2) {
		std::cout << v.back();
	}
	std::cout<<std::endl;

	fs.close();
	return 0;
}
