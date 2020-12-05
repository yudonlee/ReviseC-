#include "header2.h"
namespace header1 {
    int func(){
        foo();
        header2:::foo();
        return 1;
    }
    void foo();
    void bar();
}
/*namespace header1을 붙여주는 이유는 전역 namespace에서 충돌이 나지 않게 하기 위함이다.다른 헤더파일에 같은 함수이름을 가진게 나타난다면 충돌문제가 발생할수 있기 때문이다.*/
