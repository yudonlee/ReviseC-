#include <iostream>

class Animal {
 public:
	virtual ~Animal() {}
	virtual void speak() = 0;
};

class Dog : public Animal {
 public:
	Dog() : Animal() {}
	void speak() override { std::cout << "왈왈" << std::endl; }
};

class Cat : public Animal {
 public:
	Cat() : Animal() {}
	void speak() override { std::cout << "야옹야옹" << std::endl; }
};

int main() {
	//Animal a; pure virtual function을 포함하고 있는 abstract class는 instance 생성이 불가능 하다.
	//a.speak();
	Animal* dog = new Dog();
	Animal* cat = new Cat();

	dog->speak();
	cat->speak();
	return 0;
}

