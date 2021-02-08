#include <iostream>
#include <array>

template <typename T>
void print_array(const T& arr) {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	std::array<int, 5> arr = {1, 2, 3, 4, 5};
	std::array<int, 7> arr2 = {1, 2, 3, 4, 5, 6, 7};
	std::array<int, 3> arr3 = {1, 2, 3};

	print_array(arr);
	print_array(arr2);
	print_array(arr3);

	return 0;
}
