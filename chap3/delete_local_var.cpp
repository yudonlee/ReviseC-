#include <iostream>
using namespace std;
int main(){
    int a = 4;
    delete &a; //visual studio에서는 heap공간이 아닌 stack을 해제한다는 경고가 나온다
    cout <<" a is:"<<a<<endl;
    return 0;
}
