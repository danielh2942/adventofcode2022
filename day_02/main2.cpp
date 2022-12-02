#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main() {
	std::fstream fs;
	fs.open("input.txt",std::ios_base::in);

	if(!fs.is_open()) {
		std::cout << "error!" << std::endl;
		return 1;
	}

	std::string buff;
	int tally_a = 0, tally_b = 0;

	std::map<std::string,int> partA{
		{"A X", 4}, {"A Y", 8}, {"A Z", 3},
		{"B X", 1}, {"B Y", 5}, {"B Z", 9},
		{"C X", 7}, {"C Y", 2}, {"C Z", 6}
	};

	std::map<std::string, int> partB{
		{"A X", 3}, {"A Y", 4}, {"A Z", 8},
		{"B X", 1}, {"B Y", 5}, {"B Z", 9},
		{"C X", 2}, {"C Y", 6}, {"C Z", 7}
	};

	while(std::getline(fs,buff)) {
		if(buff == "" || buff.length() < 3) continue;

		tally_a += partA[buff];
		tally_b += partB[buff];
	}

	fs.close();

	std::cout << "Part A: " << tally_a << std::endl;
	std::cout << "Part B: " << tally_b << std::endl;

	return 0;
}
