#include <iostream>
using namespace std;

int main() {
	int** a;
	int b =4;
	*a = &b;
	cout << "A " << **a << std::endl;
	return 0;
}
