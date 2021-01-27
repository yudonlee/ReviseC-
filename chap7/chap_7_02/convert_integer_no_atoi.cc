#include <iostream>
#include <sstream>

double to_number(std::string s) {
	std::istringstream ss(s);
	double x;

	ss >> x;
	return x;
}

int main() {
	std::cout << " 1 + 2 is : " << to_number("1") + to_number("2") << std::endl;
	return 0;
}


