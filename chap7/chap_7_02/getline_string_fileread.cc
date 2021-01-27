#include <fstream>
#include <iostream>
#include <string>

int main() {
	
	std::ifstream in("test.txt");

	if (!in.is_open()) {
		std::cout << "파일을 찾을 수 없습니다!" << std::endl;
		return 0;
	}

	std::string s;
	while(in) {
		getline(in, s);
		std::cout << s << std::endl;
	}
	return 0;
}
