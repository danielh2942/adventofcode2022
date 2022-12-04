#include <iostream>
#include <fstream>
#include <string>
#include <regex>

int main() {
	std::fstream fs;
	fs.open("input.txt",std::ios_base::in);

	if(!fs.is_open()) return 1;
	
	int tally = 0;
	int overlaps = 0;

	std::regex line_form{"([0-9]+)-([0-9]+),([0-9]+)-([0-9]+)"};
	std::string buff;
	while(std::getline(fs, buff)) {
		int a,b,c,d;
		std::smatch matches;
		
		if(! std::regex_search(buff,matches, line_form)) continue;
		
		a = std::atoi(matches[1].str().c_str());
		b = std::atoi(matches[2].str().c_str());
		c = std::atoi(matches[3].str().c_str());
		d = std::atoi(matches[4].str().c_str());

		// Part 1
		if((a>=c && b <= d) || (c>=a && d<=b)) {
			tally++;
			overlaps++;
			continue;
		}

		if((a >= c && a <= d) ||
		   (b >= c && b <= d) ||
		   (c >= a && c <= b) ||
		   (d >= a && d <= b)) {
			overlaps++;
		}

	}

	fs.close();

	std::cout << "Part 1: " << tally << std::endl;
	std::cout << "Part 2: " << overlaps << std::endl;
	return 0;
}
