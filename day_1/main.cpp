#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <functional>
#include <cstdlib>

int main() {
	std::vector<int> tallies{};
	std::fstream inp;
	inp.open("input.txt",std::ios_base::in);

	if(!inp.is_open()) {
		std::cout << "Could not open file!!\n";
		return 1;
	}

	std::string temp;
	int max = 0;
	int tally = 0;
	int numElves = 1;
	while(std::getline(inp, temp)) {
		if(temp == "") {
			tallies.push_back(tally);
			if(tally > max) {
				max = tally;
			}
			tally = 0;
			numElves++;
			continue;
		}
		tally += std::atoi(temp.data());
	}

	numElves++;
	tallies.push_back(tally);
	if (tally > max) {
		max = tally;
	}

	inp.close();

	std::cout << "Part 1 Most weight carried by an elf: " << max << '\n';

	std::sort(tallies.begin(),tallies.end(), std::greater<int>());

	std::cout << "Part 2: Total calories carried by the top three elves: " << (tallies[0] + tallies[1] + tallies[2]) << '\n';
	return 0;
}
