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
	Base* p_p = &p;
	Derived* p_c = static_cast<Derived*>(p_p); //위험성을 내포하고 있다.
  //Base객체를 가르키는 포인터로 강제적 다운캐스팅을 했을떄 런타임오류를 부를 가능성이있다. 하지만 gcc 컴파일러를 통해서는 아직 런타임오류는 나타나지않았다(내의견)
	p_c->what();

	return 0;
}
