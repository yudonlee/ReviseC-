#include <iostream>
#include <string>

class Base {
	std::string s;

 public:
	Base() : s("기반") { std::cout << "기반 클래스 "<<std::endl; }

	void what() { std::cout << s << std::endl;}
};

class Derived : public Base {
	std::string s;
	
 public:
	Derived() : s("파생"), Base() { std::cout <<" 파생 클래스 "
																						<<std::endl;}
	void what() { std::cout << s << std::endl;}
};
int main() {
	Base p;
	Derived c;
	
	std::cout << "=== 포인터 버전 ===" << std::endl;
	Base* p_p = &c;
	//Derived* p_c = p_p; //컴파일러 상에서는 문제가 발생할지 몰라도 
	//실제적인 의미로 봤을때 downcasting이라도 마지막에는 derived 개겣를 가르키기 때문에 강제적 타입변환만을 거친다면 문제를 보이지 않는다.
	Derived* p_c = static_cast<Derived*>(p_p); //위험성을 내포하고 있다.
	p_c->what();

	return 0;
}
