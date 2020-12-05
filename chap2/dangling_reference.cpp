#include <iostream>
using namespace std;

int& function(int&a){
    cout<<"the address of parameter a is :"<<&a<<endl;
    a = 5;
    return a;
}
int& function2(){
    int a =2;
    return a;
}
int main(){
    //int& error = function2();// 참조해야할 원본이 사라짐.그리하여 dangling reference 발생.하지만 현실적으론 
    //cout <<"error is :"<<error<<endl; gcc 컴파일러에서는 에러가 발생하나 visual studio에서는 발생하지 않는것으로 확인되고 있음.하지만 그렇다고 해도 이것은 undefined bevaior로서 굉장히 불안정한 코드이므로 사용하지 않아야 함.
    const int& no_error = function2(); // 원래 함수의 리턴값은 해당 문장이 끝나면 소멸됨, 하지만 예외적으로 상수 레퍼런스로 리턴값을 받게 되면 리턴값 생명이 연장됨.
    int b = 2;
    cout<<"the address of b is "<<&b<<endl;
    int& c = function(b);
    int d = function(b);
    cout<<"the address of c is "<<&b<<endl;
    return 0;
}
