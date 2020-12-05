#include <iostream>

int change_val(int *p){
    *p = 3;
    return 0;
}
int main(){
    int number =5;
    //  int& lvalue_error; reference할때는 반드시 지정해줘야한다 그렇지 않으면 에러가 남.
    int& another_number = number;
    int& other_number = another_number;
    int* address = &number;
    int* reference_address = &another_number;
    int* other_ref_address = &other_number;
    std::cout<<number<<std::endl;
    change_val(&number);
    std::cout << number << std::endl;
    std::cout << another_number << std::endl;
    std::cout << other_number << std::endl;
    std::cout << address << std::endl;
    std::cout << reference_address << std::endl;
    std::cout << other_ref_address << std::endl;

    return 0;
}
