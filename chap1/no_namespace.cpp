#include <iostream>

namespace {
int OnlyInThisFile(){
    return 0;
}
int only_in_this_file = 0;

int main(){
    std::cout<<"function is :"<<OnlyInThisFile()<<std::endl;
    only_in_this_file = 3;
    std::cout<<"global value is:"<<only_in_this_file<<std::endl;
    return 0;
}

