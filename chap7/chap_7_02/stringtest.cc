#include <iostream>
#include <string>
using namespace std;
int main() {
	string s,ss;
	char A = 'Z';
	int B = A - '@';
	char a;
	cin >> s >> a >> ss;
	cout << s << " char is: "<< a <<"string : " << ss << endl;
	int aa = s[0] - '0';
	cout << "aa is: " << aa << endl;
	cout << "B is :" << B <<endl;
	return 0;
}
