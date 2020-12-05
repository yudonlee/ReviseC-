#include <iostream>

class A{
	mutable int data_;
	//int data_;    << this can't be changed by void const function

 public:
	A(int data) : data_(data) {}
	void DoSomething(int x) const{
		data_ = x;
	}

	void PrintData() const { std::cout << "Data :" << data_ << std::endl;}
};

int main(){
	A a(10);
	a.DoSomething(3);
	a.PrintData();
	return 0;
}
