#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ofstream out("test.txt");

	std::string s;
	if (out.is_open()) {
		out << "i am working in baek nam hak sool gwan." ;
	}  
	
	return 0;
}
