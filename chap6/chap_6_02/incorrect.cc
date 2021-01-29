#include <iostream>
#include <string>

class Base {
	std::string s;

 public:
	Base() : s("기반") { std::cout << "기반 클래스 "<<std::endl; }

	virtual void that() { std::cout <<"기반 클래스의 that(override x) " << std::endl; }
	virtual void incorrect() { std::cout << "기반 클래스" << std::endl;}
};

class Derived : public Base {
	std::string s;
	
 public:
	Derived() : s("파생"), Base() { std::cout <<" 파생 클래스 "
																						<<std::endl;}
	void that() const{ std::cout << "파생 클래스의 that(override x) " 
		   										<< std::endl; }
	// error void incorrect() const override { std::cout << "파생 클래스 " << std::endl;}
	void incorrect() override { std::cout << "파생 클래스 " << std::endl;}
};
int main() {
	Base p;
	Derived c;
	
	Base* p_c = &c;
	Base* p_p = &p;
	
	std::cout << " 두 포인터 모두 Base type  " << std::endl;
	std::cout << " == 실제 객체는 Base == " << std::endl;
	p_p->that(); //같은 결과가 나오는 이유는 컴파일러상에서 const가 붙은 상수함수와 그냥 함수를 다른 함수로 보기 때문에 호출할때 차이가 난다. 그리하여 override의 키워드를 붙였음에도 컴파일러상에서 에러가 난다.
	p_p->incorrect();
	std::cout << " == 실제 객체는 Derived == " << std::endl;
	p_c->that();
	p_c->incorrect();

	return 0;
}
