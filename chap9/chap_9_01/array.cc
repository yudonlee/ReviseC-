#include <iostream>
#include <array>

void print_array(const std::array<int, 5>& arr) {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
int main() {
	
	std::array<int, 5> arr = {1, 2, 3, 4, 5};

	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
