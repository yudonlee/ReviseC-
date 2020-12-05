#include <iostream>
using namespace std;
class A{
  int x;

 public:
  A(int c) : x(c) {
    cout<<"address of x"<<&x<<endl;;
  }
  int& access(){
    cout<<"address of x"<<&x<<endl;;
    return x;
  }
  int getX() const{
    return x;
  }

};
int main(){
  A a(3);
  int& b = a.access();
  b = 4;
  
  cout << "x is: "<<a.getX()<<endl;
  return 0;
}
