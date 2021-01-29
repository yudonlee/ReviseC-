#include <iostream>
//prefix는 값이 바뀐 자기 자신을 리턴, postfix는 값이 바뀌기 이전의 객체를 리턴해주어야 한다.

//한가지만 기억하자면 결국 전위증감은 바뀐 자신을, 후위증감은 바뀐 내가 아닌 바뀌지 않은 나의 모습을 복사해서 보여주는것.
//전위 증감은 연산 수행후 자기자신을 return해주면 되지만 후위증감은 복사생성자를 불러 임시객체를 만든뒤 리턴해줄수 밖에 없다. 값이 바뀌기 이전의 객체를 리턴해주어야 하기 때문이다.
class Test {
	int x;
 public:
  Test(int x) : x(x) {}
  Test(const Test& t) : x(t.x) {}
  Test& operator++() {
	  x++;
    std::cout << "전위 증감 연산자" << std::endl;
    return *this;
	}

					  // 전위 증감과 후위 증감에 차이를 두기 위해 후위 증감의 경우 인자로 int 를
					  // 받지만 실제로는 아무것도 전달되지 않는다.
	Test operator++(int) {
  	Test temp(*this);
  	x++;
		std::cout << "후위 증감 연산자" << std::endl;
  	return temp;
	}
	int get_x() const {
		return x;
  }
};

void func(const Test& t) {
	  std::cout << "x : " << t.get_x() << std::endl;
}

int main() {
	  Test t(3);
	  func(++t); // 4
	  func(t++); // 4 가 출력됨
	  std::cout << "x : " << t.get_x() << std::endl;
}
