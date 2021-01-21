#include <iostream>

class A {
 public:
	int a;
 	
	A() { std::cout << "A 생성자 호출" << std::endl; }
};

class B {
 public:
	int b;
	
	B() { std::cout << "B 생성자 호출" << std::endl; }
};

class C : public A, public B { //상속하는 순서에 따라 호출순서가 결정
 public:
	int c;

	C() : A(), B() { std::cout << "C 생성자 호출" << std::endl; }
};
class D : public B, public A { //상속하는 순서에 따라 호출 순서가 결정
 public:
	D() : A(), B() { std::cout << "D 생성자 호출" << std::endl;}
};
int main() { 
	C c; 
	D d;
	return 0;
}
	


