#include <fstream>
#include <iostream>
#include <string>

int main() {
	std::ifstream in("test.txt");
	char buf[100];

	if (!in.is_open()) {
		std::cout << "파일을 찾을 수 없습니다!" << std::endl;
		return 0;
	}
	
	while (in) {
		in.getline(buf, 5, '.');
		std::cout << buf << std::endl;
	}
	
	return 0;
}
