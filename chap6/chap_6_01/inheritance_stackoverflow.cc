#include <iostream>
#include <string>

class message {
	std::string the_message;
 public:   
	message() : the_message("default string") {}
  message(std::string a) : the_message(a) {}
  virtual ~message() = default;
  virtual void foo() { std::cout << the_message << std::endl; }
	virtual void too() { std::cout << the_message << std::endl; }
};

class message_sub : public message {
	int the_message;
 public:
	message_sub(int a) : the_message(a) {}
	void too() { std::cout << the_message << std::endl; }
};

int main(int, char**) {
	message *a_message = new message_sub(12);
	a_message->foo();
	a_message->too();
	delete a_message;
}
