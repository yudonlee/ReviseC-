#include <iostream>
#include <sstream>

int main() {
	std::istringstream ss("123");
	int x;
	ss >> x;

	std::cout << "입력 받은 데이터 " << x << std::endl;

	return 0;
}
