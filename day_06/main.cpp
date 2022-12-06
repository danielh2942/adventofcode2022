#include <iostream>
#include <fstream>
#include <string>
#include <set>

int main() {
	std::ifstream fs{"input.txt"};
	
	if(!fs.is_open()) return 1;
	
	std::string buff;
	std::getline(fs,buff);

	// Part 1
	for(int i = 0; i < buff.size() - 4; i++) {
		std::set<char> mSet{buff[i],buff[i+1],buff[i+2],buff[i+3]};
		if(mSet.size() == 4) {
			std::cout << i + 4 << std::endl;
			break;
		}
	}

	// Part 2
	for(int i = 0; i < buff.size() - 14; i++) {
		std::set<char> mSet2{};
		for(int j = 0; j < 14; j++) {
			mSet2.insert(buff[i+j]);
		}
		if(mSet2.size() == 14) {
			std::cout << i + 14 << std::endl;
			break;
		}
	}

	fs.close();
	return 0;
}

