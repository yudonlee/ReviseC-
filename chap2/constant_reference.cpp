#include <iostream>

int main(){
    const int& ref = 4;
    int a = ref;
    const int& c = a;
    std::cout <<"before c is:"<<c<<std::endl;
    a = 5;
    std::cout <<"after c is:"<<c<<std::endl;
    //a = 5; 바본가 ? 값을 복사하는거지 reference를....
    //std::cout<< ref <<"  " << a <<std::endl;
    return 0;
}
