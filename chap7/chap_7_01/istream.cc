#include <iostream>
#include <string>

int main() {
	int t;
	while(true){
		std::cin.setf(std::ios_base::hex, std::ios_base::basefield);
		std::cin >> t;
		std::cout << "입력 :: " << t << std::endl;
		if(std::cin.fail()) {
			std::cout << "please input again!" << std::endl;
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		if(t == 1) break;
	}
}
