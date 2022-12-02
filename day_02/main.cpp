#include <iostream>
#include <fstream>
#include <string>

#define ROCK		1
#define PAPER		2
#define SCISSORS	3

int main() {
	std::fstream fs;
	fs.open("input.txt",std::ios_base::in);
	
	if(!fs.is_open()) {
		std::cout << "Could not open file!" << std::endl;
		return 1;
	}

	std::string buff;
	int tally = 0;
	int tally2 = 0;

	char move1 = 0;
	char move2 = 0;
	while(std::getline(fs,buff)) {
		if(buff == "" || buff.length() < 3) {
			continue;
		}
		// Rock		A X
		// Paper	B Y
		// Scissors	C Z
		move1 = buff[0] - '@';
		move2 = buff[2] - 'W';
		if(move1 == move2) {
			// Tie
			tally += 3;
		}
		if(move1 < move2) {
			if(!((move2 == SCISSORS) && (move1 == ROCK))) {
				tally += 6;
			}
		}

		if((move1 == SCISSORS) && (move2 == ROCK)) {
			tally += 6;
		}

		tally += move2;

		// Part 2
		// Rock		A
		// Paper	B
		// Scissors	C

		// Loss		X
		// Draw		Y
		// Win		Z
		switch(move2) {
			case 1: // Loss
				if (move1 == ROCK) {
					tally2 += SCISSORS;
				} else {
					tally2 += (move1 - 1);
				}
				break;
			case 2: // Draw
				tally2 += 3 + move1;
				break;
			case 3:	// Win
				if (move1 == SCISSORS) {
					tally2 += 6 + ROCK;
				} else {
					tally2 += move1 + 7;
				}
				break;
		}
	}

	fs.close();

	std::cout << "Part 1: Tally: "<< tally << std::endl;
	std::cout << "Part 2: Tally: " << tally2 << std::endl;
	return 0;
}
