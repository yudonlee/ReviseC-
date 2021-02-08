#include <iostream>

template <typename T, int num = 5>
T add_num(T t) {
	return t + num;
}

int main() {
	int x = 3;
	std::cout << "x : " << add_num(x) << std::endl;
	return 0;
}
