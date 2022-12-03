#include <algorithm>
#include <iostream>
#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include <set>

int main() {

	std::vector<std::string> backpacks{};

	std::fstream fs;
	fs.open("input.txt", std::ios_base::in);

	if(!fs.is_open()) return 1;
	
	int tally = 0;

	std::string buff;
	while(std::getline(fs,buff)) {
		// Part 1
		std::string front{buff.begin(),buff.begin()+(buff.length()/2)};
		std::string back{buff.begin()+(buff.length()/2),buff.end()};
		std::set<char> duplicates{};
		for(int i = 0; i < front.length(); i++) {
			if(duplicates.contains(front[i])) continue;
			for(int j = 0; j < back.length(); j++) {
				if(front[i] == back[j]) {
					if((front[i] <= 'Z') && (front[i] >= 'A')) {
						tally += ((front[i] - 'A') + 27);
					} else {
						tally += ((front[i] - 'a') + 1);
					}
					duplicates.insert(front[i]);
					break;
				}
			}
		}

		backpacks.push_back(buff);
	}
	fs.close();

	std::cout << "Part 1: " << tally << std::endl;
	// Part 2	
	int tally_2 = 0;
	for(int i = 0; i < backpacks.size(); i+=3) {
		std::set<char> duplicates{};
		std::set<char> shared_a{};
		std::set<char> shared_b{};
		for(int j = 0; j < backpacks[i].length(); j++) {
			if(duplicates.contains(backpacks[i][j])) continue;
			duplicates.insert(backpacks[i][j]);

			for(int k = 0; k < backpacks[i+1].length(); k++) {
				if(shared_a.contains(backpacks[i+1][k])) continue;
				if(backpacks[i][j] == backpacks[i+1][k]) {
					shared_a.insert(backpacks[i+1][k]);
					break;
				}
			}

			for(int k = 0; k < backpacks[i+2].length(); k++) {
				if(shared_b.contains(backpacks[i+2][k]))continue;
				if(backpacks[i][j] == backpacks[i+2][k]) {
					shared_b.insert(backpacks[i+2][k]);
					break;
				}
			}
		}

		std::set<char> intersection{};

		std::set_intersection(shared_a.begin(),shared_a.end(),
							  shared_b.begin(),shared_b.end(),
							  std::inserter(intersection,intersection.begin()));
		for(const auto& v: intersection) {
			if((v <= 'Z') && (v >= 'A')) {
				tally_2 += ((v - 'A') + 27);
			} else {
				tally_2 += ((v - 'a') + 1);
			}
		}
	}

	std::cout << "Part 2: " << tally_2 << std::endl;

	return 0;
}
