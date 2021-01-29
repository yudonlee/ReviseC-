#include <iostream>
int main(){
	int* a = new int[10];
	for(int i = 0 ; i < 10; i++){
		int* b = a + i;
		void* c = static_cast<void *>(a) + i;
		std::cout << "b is : "<< b << "\nc is : "<<c<<std::endl; 
	}
	return 0;
}
