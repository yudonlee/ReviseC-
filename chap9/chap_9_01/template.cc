#include <iostream>
#include <string>

template <typename T>
//template <class T> 가 가능하지만 typename을 쓰기를 권고한다. 처음 개발자 bjarne stroustrup은 새로운 키워드를 만들고 싶지 않았기에 class T를 사용하였으나 후대에 들어서는 class T에서 T는 반드시 class만이 가능하다는 혼동을 줄 수 있다고 생각해 새로운 걸 만들게 됨.
class Vector {
	T* data;
	int capacity;
	int length;

 public:
	Vector(int n = 1) : data(new T[n]), capacity(n), length(0) {}

	void push_back(T s) {
		if (capacity <= length) {
			T* temp = new T[capacity * 2];
			for (int i = 0; i < length; i++) {
				temp[i] = data[i];
			}
			delete [] data;
			data = temp;
			capacity *= 2;
		}

		data[length] = s;
		length++;
	}

	T operator[](int i) { return data[i]; }

	void remove(int x) {
		for (int i = x + 1; i < length; i++) {
			data[i - 1] = data[i];
		}
		length--;
	}
	
	int size() { return length; }

	~Vector() {
		if (data) {
			delete[] data;
		}
	}
};

int main() {
	Vector<int> int_vec;
	int_vec.push_back(3);
	int_vec.push_back(2);
	std::cout << "int vector\n";
	std::cout <<"first factor : "<< int_vec[0] <<"\n" << "second factor : " << int_vec[0] << "\n";

	Vector<std::string> str_vec;
	str_vec.push_back("hello");
	str_vec.push_back("world");
	std::cout <<"string vector\n";
	std::cout << "frist factor : " << str_vec[0] << "\n" << "second factor : " << str_vec[1] << "\n";

	return 0;
}
