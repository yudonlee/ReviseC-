#include <iostream>
#include <string>
#include <cstdlib>
class Complex{
 private:
	double real , img;
 
 public:
	Complex(const char* str);
	Complex(double real, double img) : real(real), img(img){}
	Complex(const Complex& c){real = c.real, img = c.img;
		std::cout<<"복사생성자 호출"<<std::endl;
	}
	Complex operator+(const Complex& c) const; 
	Complex& operator=(const Complex& c);
	//Complex& operator+=(const Complex& c);
	
	void println(){ std::cout << "( "<<real << " , "<<img<<")\n";}
	friend std::ostream& operator<<(std::ostream& os, const Complex& c);
};
Complex::Complex(const char* str){

	real = 0.0, img = 0.0;
	std::string s(str);
	int starting_point_of_partition = -1;
	int length = s.length();
	for(int i = length -1 ; i > -1; i--){
			if( str[i] == '+' || str[i] == '-'){
						starting_point_of_partition = i;
						break;
			}
	}
	if(starting_point_of_partition == 0 || starting_point_of_partition == -1){
			if(str[length-1] == 'i')
				img = atof( (s.substr(0, starting_point_of_partition)).c_str());
			else
				real = atof(str);
	}
	else{
			if(str[starting_point_of_partition-1] == 'i'){
					img = atof((s.substr(0, starting_point_of_partition-1)).c_str());
					real = atof((s.substr(starting_point_of_partition)).c_str());	
			}
			else{
				real = atof((s.substr(0, starting_point_of_partition)).c_str());
					img = atof((s.substr(starting_point_of_partition, length - starting_point_of_partition-1)).c_str());
								
			}
		
	}
}
/*Complex Complex::operator+(const char* str) const {
	Complex cstr(str);
	Complex temp(real + cstr.real, img + cstr.img);
	return temp;
}*/
Complex Complex::operator+(const Complex& c) const{
	Complex temp(real + c.real, img + c.img);
	return temp;
}
Complex& Complex::operator=(const Complex& c){
	real = c.real;
	img = c.img;
	return *this; 
}
Complex operator+(const Complex& a,const Complex& b){
	return a.operator+(b);
	//return a+b 하면 인식을 못함.
}

std::ostream& operator<<(std::ostream& os, const Complex& c){
	os << "( " << c.real << " , " << c.img << " ) ";
	return os;
}

int main() {
	Complex a(0,0);
	a = "-1.1+3i" + a;
	a.println();
	a = "-2.3+3i" + a;
	a.println();
	std::cout<<a<<std::endl;
	return 0;
}
