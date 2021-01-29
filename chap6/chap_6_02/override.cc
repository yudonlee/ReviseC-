#include <iostream>
#include <string>

class Base {
	std::string s;

 public:
	Base() : s("기반") { std::cout << "기반 클래스 "<<std::endl; }

	void that() { std::cout <<"기반 클래스의 that(virtaul x) " << std::endl; }
	virtual void what() { std::cout << "기반 클래스의 what " 
																	<< std::endl;}
};

class Derived : public Base {
	std::string s;
	
 public:
	Derived() : s("파생"), Base() { std::cout <<" 파생 클래스 "
																						<<std::endl;}
	void that() { std::cout << "파생 클래스의 that(virtaul x) " 
		   										<< std::endl; }
	void what() override  { std::cout << "파생 클래스의 what " << std::endl;}
};
int main() {
	Base p;
	Derived c;
	
	Base* p_c = &c;
	Base* p_p = &p;
	
	std::cout << " 두 포인터 모두 Base type  " << std::endl;
	std::cout << " == 실제 객체는 Base == " << std::endl;
	p_p->that();
	p_p->what();
	std::cout << " == 실제 객체는 Derived == " << std::endl;
	p_c->that();
	p_c->what();

	return 0;
}
