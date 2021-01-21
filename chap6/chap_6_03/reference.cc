#include <iostream>

class A {
 public:
	virtual void show() { std::cout << "Parent !" << std::endl; }
	void show_() { std::cout << "Parent !(no virtual)" << std::endl; }
};
class B : public A {
 public:
	void show() override { std::cout << "Child!" << std::endl; }
	void show_() { std::cout << "Child!(no virtual)" << std::endl; }
};

void test(A& a) { 
	a.show(); 
	a.show_();
}
int main() {
	A a;
	B b;
	test(a);
	test(b);
	return 0;
}
