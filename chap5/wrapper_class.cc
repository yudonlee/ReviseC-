#include <iostream>
class Int{
	int data;
 
 public:
	Int(int data) : data(data) {}
	Int(const Int& i) : data(i.data) {}
	operator int() {return data;} //복소수에서도 봤듯이 연산자 오버로딩을 일일이 전부 해줘야 하는 일은 장난이 아니기 때문에 이렇게 편리하게 type casting을 overloading해주어도 된다.
};

int main(){
	Int x =3;
	int a = x + 4;
	x = a * 2 + x * 4;
	std::cout << x << std::endl;
}


