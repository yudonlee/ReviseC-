#include <iostream>
#include <string>

int main() {
	int t;
	while(true) {
		std::cin >> t;
		std::cout << "입력 :: " << t << std::endl;
		if (std::cin.fail()) {
			std::cout << "please input correctly." << std::endl;
			std::cin.clear();
			std::cin.ignore(100,'\n');
		}
		if (t == 1) break;
	}
} 
