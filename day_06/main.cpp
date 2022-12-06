#include <cstdint>
#include <iostream>
#include <fstream>
#include <string>
#include <bit>

int main() {
	std::ifstream fs{"input.txt"};
	
	if(!fs.is_open()) return 1;
	
	std::string buff;
	std::getline(fs,buff);

	// ASCII [A-z] has a distance of 62 so I can bitmask a uint64
	// and then use popcount to count the number of activated bits

	// Part 1
	for(int i = 0; i < buff.size() - 4; i++) {
		std::uint64_t bitmask = 0U;
		bitmask |= 1U << (buff[i] - 'A');
		bitmask |= 1U << (buff[i+1] - 'A');
		bitmask |= 1U << (buff[i+2] - 'A');
		bitmask |= 1U << (buff[i+3] - 'A');

		if(std::popcount(bitmask) == 4) {
			std::cout << i + 4 << std::endl;
			break;
		}
	}

	// Part 2
	for(int i = 0; i < buff.size() - 14; i++) {
		std::uint64_t bitmask = 0U;
		for(int j = 0; j < 14; j++) {
			bitmask |= 1U << (buff[i+j] - 'A');
		}
		if(std::popcount(bitmask) == 14) {
			std::cout << i + 14 << std::endl;
			break;
		}
	}

	fs.close();
	return 0;
}

