#include <iostream>
using namespace std;
int main(){
	char* test = new char[10];
	test[0] = 'a', test[1] = 'b';
	test[2] = '0';
	int i = 0;
	while(test[i] != 0){
			cout << "test["<<i<<"] is : "<< test[i] <<endl;
			i++;
	}
	return 0;
}
