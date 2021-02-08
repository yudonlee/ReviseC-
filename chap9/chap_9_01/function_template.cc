#include <iostream>
#include <string>

template <typename T>
T max(T& a, T& b) {
	return a > b ? a : b;
}
class example {
	int data;
 public:
	example(int x) : data(x) {}
	int GetData() { return data; }
	friend bool operator>(const example &left, const example &right);
};

bool operator>(const example &left, const example &right) {
	if (left.data > right.data)
		return true;
	return false;
}

int main() {
	int a = 1, b = 2;
	std::cout << "Max (" << a << "," << b << ") ? : " << (a, b) << "\n";

	std::string s = "hello", t = "world";
	std::cout << "Max (" << s << "," 
						<< t << ") ? : " << max(s, t) << "\n";
	example* e1 = new example(3);
	example* e2 = new example(4);
	example e3(5), e4(6);	
	std::cout << "Max (" << e1->GetData() << "," << e2->GetData() << ") ? : " << max(e1, e2)->GetData() << "\n";
	std::cout << "Max (" << e3.GetData() << "," << e4.GetData() << ") ? : " << max(e3, e4).GetData() << "\n";
	return 0;
}
