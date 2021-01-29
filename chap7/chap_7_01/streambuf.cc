#include <iostream>
#include <string>

int main() {
	std::string s;
	std::cin >> s;

	// 위치 지정자를 한 칸 옮기고 그 다음 문자를 확인한다 ( 이때 움직이지 않음 엿본다는 개념이지 읽는 것이 아님. streambuf 객체에서 읽기 되면 스트림의 위치 지정자ㅡㄹ 한칸 전진시키는 반면 엿본다는것은 스틤 위치 지정자를 움직이지 않는다 는 것)
	char peek = std::cin.rdbuf()->snextc();
	if (std::cin.fail()) std::cout << "Failed";
	std::cout << "두 번째 단어 맨 앞글자 : " << peek << std::endl;
	std::cin >> s;
	std::cout << "다시 읽으면 : " << s << std::endl;
	return 0;
}
