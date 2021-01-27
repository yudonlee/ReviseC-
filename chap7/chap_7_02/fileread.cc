#include <fstream>
#include <iostream>
#include <string>

int main() {
	std::ifstream in("test.txt");
	std::string s;

	if(in.is_open()) {
		//위치 지정자 파일 끝으로 옮기기
		in.seekg(0, std::ios::end);
		
	//그위치를 읽는다 즉 파일끝에서 위치를 읽기 떄문에 파일의크기와 동일
		int size = in.tellg();

		//그 크기의 문자열 할당
		s.resize(size);

		// 위치 지정자를 다시 파일 맨 앞으로 옮긴다.
		in.seekg(0, std::ios::beg);

		//파일 전체 내용 읽고 문자열 저장
		in.read(&s[0], size);
		std::cout << s;
	}
	else {
		std::cout << "파일을 찾을 수 없습니다.!" << std::endl;
	}
	
	return 0;
}
