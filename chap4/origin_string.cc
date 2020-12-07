#include <iostream>

class string{
  char *str = nullptr;
  int len = 0;
 
 public:
  string(char c, int n);
  string(const char* s);
  string(const string &s);
  ~string();
  
  int strlen();
  char* find(const char* s);
  
  void add_string(const string &s);
  void copy_string(const string &s);
  void show_string();
  
  bool StringCompare(const string &s);
  bool is_equal(string &s);
};

string::string(char c, int n){
  str = new char[n+1];
  for(int i=0; i<n;i++)  str[i] = c;
  str[n] = 0;
  len = n;
}
string::string(const char *s){
  int s_len =0;
  while(s[s_len] != 0)
    s_len++;
  str = new char[s_len + 1];
  for(int i=0; i<s_len; i++) str[i] = s[i];
  str[s_len + 1] = '\0';
  len = s_len;
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
}

char* find(const string& s){
  char* result = new char[len+1];
  for(int i = 0,index =0 ; i< len; i++){
    if(str[i] == s.str[i])
      result[index++] = str[i];
  }
  return result;
}

void string::add_string(const string &s){
  int s_len = s.len;
  char* result = new char[len + s_len+1];
  for(int i = 0;i < len;i++) result[i] = str[i];
  for(int i = len; i < s_len + len; i++) result[i] = s.str[i-len];
  delete str;
  str = result;
  len += s_len;
  str[len] = 0;
}
void string::copy_string(const string &s){
  int s_len = s.len;
  char* result = new char[s_len+1];
  for(int i =0; i < s_len; i++)  
    result[i] = s.str[i];
  result[s_len] = 0;
  delete str;
  str = result;
  len = s_len;
}
int string::strlen() /*const*/{
  return len;
}
void string::show_string(){
  std::cout<<"string is :"<<str<<std::endl;
}
