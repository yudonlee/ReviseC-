#include <iostream>
#include <string>

class Base {
 protected:
	std::string s;

 public:
	Base() : s("기반") { std::cout << "기반 클래스" << std::endl; }
	
	void what() { std::cout << s << std::endl;}
};

class Derived : public Base {
	std::string s;

 public:
	Derived() : Base() , s("파생") {
		std::cout << "파생 클래스" << std::endl;

		what();
	}
	
	void what() { std::cout << s << std::endl; } 
};
int main() {
	std::cout << " === 기반 클래스 생성 ===" << std::endl;
	Base p;
	Base* p_p = &p;
	p_p->what();
	std::cout << " === 파생 클래스 생성 ===" << std::endl;
	Derived c;
	p_p = &c;
	Derived* p_c =&c;
	p_p->what();
	p_c->what();
	return 0;
}

