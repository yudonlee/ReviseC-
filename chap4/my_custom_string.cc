#include <iostream>

class string{
  char *str = nullptr;
  int len = 0;
	int memory_capacity = 0; 
 public:
  string(char c);
  string(const char* s);
  string(const string &s);
  ~string();
  
  int str_len() const;

	void reserve(int size);
	int capacity() const;

	char at(const int index);

	int find(const char s, const int index);
	int find(const char* s, const int index);
 	int	find(const string &s, const int index);
  
	string& assign();
	string& insert(const char s, const int index);
	string& insert(const char* s, const int index);
	string& insert(const string& s,const int index);
	string& erase(const int index, const int count);

	bool compare(const string& s);
  
	void show_string();
	/*void add_string(const string &s);
  void copy_string(const string &s);
  void show_string();
	*/  
};

string::string(char c){
  str = new char[2];
  str[0] = c, str[1] = '\0';
  len = 1;
	memory_capacity = len;
}
string::string(const char *s){
  int s_len =0;
  while(s[s_len] != 0)
    s_len++;
  str = new char[s_len + 1];
  for(int i=0; i<s_len; i++) str[i] = s[i];
  str[s_len + 1] = '\0';
  len = s_len;
	memory_capacity = len;
}
string::string(const string &s){
  //int s_len = s.strlen();
  int s_len = s.len;
  str = new char[s_len + 1];
  for(int i =0; i < s.len; i++)
    str[i] = s.str[i];
  str[s_len] = 0;
  len = s_len;
}
string::~string(){
  if(str != nullptr)
    delete str;
	//len = 0;
}

int string::str_len() const{
  return len;
}
void string::reserve(int size){
	if(size > memory_capacity){
		char* temp = new char[ size + 1 ];
		temp[size] = '\0';
		for(int i = 0; i < len; i++)
			temp[i] = str[i];
		delete[] str;
		str = temp;
		memory_capacity = size;
	}
}
int string::capacity() const{
	return memory_capacity;
}
/*int string::strlen(const char* s) const{
	int length = 0;
	whil(s[length] != 0)
		length++;
	return length;
}*/

char string::at(const int index){
	if( 0 <= index && index < len)
		return str[index];
	else
		return '\0';
}

int string::find(char c, const int index){
	int result = 0;
	if(len < 0 || index < 0 || len < index ) return 0;
	for(int i = index; i < len; i++)
		if(str[i] == c)
			result++;
	return result;
}
int string::find(const char* s, const int index){	
	int result = 0;
	if( len < 0 || index < 0 ) return 0;
	int s_length = 0;
	while(s[s_length] != 0)
		s_length++;
	if( len < index + s_length - 1 ) return 0;
	for(int i = index; i + s_length - 1	< len; i++){ //문자열의 크기만큼 index로부터 불러올수 없다면 확인할 필요가 없다. 예를들어 문자열의 크기가 10이다. 비교하는 문자열의 크기는 4이다. 그렇다면 index가 7이상일때 비교할 필요가 있는가? x 
			for(int j = 0; j < s_length; j++){
				if(str[i+j] != s[j])
					break;
				if( j == s_length - 1)
					result++;
			}
	}
	return result;	
}
int	string::find(const string &s, const int index){
	int result = 0;
	int s_length = s.str_len();
	if( len < 0 || index < 0 || len < index + s_length - 1 )
		return 0;
	for(int i = index; i + s_length - 1 < len; i++){
			for(int j = 0; j < s_length; j++){
				if(str[i+j] != s.str[j])
					break;
				if( j == s_length - 1)
					result++;
			}
	}
	return result;	
}
string& string::insert(const char s,const int index){
	string temp(s);
	return insert(temp, index);
}
string& string::insert(const char* s,const int index){
	string temp(s);
	return insert(temp, index);
}

//이부분은 본문의 아이디어를 참고함. 오버로딩했더라도 생성자를 통해 이런식으로 깔끔하게 처리를 하는 것이 가능함.
string& string::insert(const string& s,const int index){
	if( index < 0 || index > len ) return *this;
	int s_length = s.str_len();
	reserve(s_length + len);
	for(int i = index; i < len; i++)
		str[i+s_length] = str[i];
	for(int i = 0; i < s_length; i++)
		str[i+index] = s.str[i];
	len += s_length;
	
	return *this;	
}
string& string::assign(){
	if(memory_capacity > len){
			char* temp = new char[len + 1];
			for(int i = 0; i < len; i++)
				temp[i] = str[i];
			delete[] str;
			str = temp;
			memory_capacity = len;
			str[len] = '\0';
			return *this;
	}
	else
		return *this;
}
string& string::erase(const int index, const int count){
	if( index < 0 || count < 0 || index + count - 1 > len )
		return *this;
	if( index + count == len ){
			len -= count;
			return assign();
		/*char* temp = new char[len - count + 1];
			for(int i = 0; i < len - count + 1; i++)
				temp[i] = str[i];
			delete[] str;
			str = temp;
			len = len - count;
			capacity = len - count;
			str[len] = '\0';*/
	}
	else{
		len -= count;
		//char* temp = new char[len - count + 1];
		for(int i = 0; i < count; i++)
			str[index + i] = str[index+count+i];
		return assign();
		/*for(int i = 0; i < len - count + 1;i++)
			temp[i] = str[i];
		delete[] str;
		str = temp;
		len = len - count;
		capacity = len - count;
		str[len] = '\0';*/
	}
	return *this;
}
//bool compare(const char s);
void string::show_string(){
  std::cout<<"string is :"<<str<<std::endl;
}

int main(){
	string a("bcV");
	a.show_string();
	string b("aalalas");
	b.show_string();
	a.insert("aaabb",1);
	a.show_string();
	b.erase(3,3);
	b.show_string();
	return 0;
}
