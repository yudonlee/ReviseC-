#include <fstream>
#include <iostream>
#include <string>

int main() {
	std::ifstream in ("test.txt");
	std::string s;
	
	if (in.is_open()) {
		in>> s;
		std::cout << "입력 받은 문자열 :: " << s << std::endl;
	}
	else {
		std::cout << "파일을 찾을 수 없습니다!" << std::endl;
	}

	in.close();
	in.open("other.txt");

	if (in.is_open()) {
		in >> s;
		std::cout << "입력 받은 문자열:: " << s << std::endl;
	}
	else {
		std::cout << "파일을 찾을 수 없습니다!" << std::endl;
	}
	return 0;
}
