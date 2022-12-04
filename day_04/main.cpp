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
	int a,b,c,d;
	while(std::getline(fs, buff)) {
		std::smatch matches;
		
		if(! std::regex_search(buff,matches, line_form)) continue;
		
		a = std::stoi(matches[1]);
		b = std::stoi(matches[2]);
		c = std::stoi(matches[3]);
		d = std::stoi(matches[4]);

		// Part 1
		tally += ((a-c) * (b-d) <= 0);
		// Part 2
		overlaps += ((a-d) * (b-c) <= 0);

	}

	fs.close();

	std::cout << "Part 1: " << tally << std::endl;
	std::cout << "Part 2: " << overlaps << std::endl;
	return 0;
}
