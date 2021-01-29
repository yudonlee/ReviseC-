#include <iostream>
#include <string>

class Base {
 std::sring base_string; // private area
// protected:
//std::string base_string;

 public:
	Base() : base_string("기반") { std::cout << "기반 클래스" << std::endl; }
	
	void what() { std::cout << base_string << std::endl;}
};

//class Derived : public Base {
class Derived: protected Base{
	std::string derived_string;

 public:
	Derived() : Base() , derived_string("파생") {
		std::cout << "파생 클래스" << std::endl;
		
		base_string = "Change";
		std::cout << base_string << std::endl;
	}
	
	void what() { std::cout << derived_string << std::endl; } 
};
int main() {
	std::cout << " === 기반 클래스 생성 ===" << std::endl;
	Base p;

	std::cout << " === 파생 클래스 생성 ===" << std::endl;
	Derived c;

	return 0;
}

