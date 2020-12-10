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
	//Complex operator+(const Complex& c, const char* str) const;
	Complex operator+(const char* str) const;
	Complex operator+(const Complex& c) const; //const 붙여주는 이유! 내부 인자가 바뀌지 않기떄문에 const를 붙여준다.
	Complex operator-(const Complex& c) const;
	Complex operator*(const Complex& c) const;
	Complex operator/(const Complex& c) const;
	//Complex& 를 사용하지 않는 이유: reference로 리턴하게 되면 속도저하는 발생하지 않지만 처리되는 결과에서 의도하지 않는 결과들이 일어날 수 있다. 내부에서 읽기만 수행되고 값이 바뀌지 않기 때문에 const키워드를 붙이는게 옳다. 인자의 값이 함수내부에서 바뀌지 않는다고 확신할떄는 const 키워드를 붙여준다. 상수 함수로 선언할 수 있을경우 상수로 선언하고,  사칙연산은 반드시 값을 리턴해주어야 한다.
	Complex& operator=(const Complex& c);
	Complex& operator+=(const Complex& c);
	Complex& operator-=(const Complex& c);
	Complex& operator*=(const Complex& c);
	Complex& operator/=(const Complex& c);
	void println(){ std::cout << "( "<<real << " , "<<img<<")\n";}
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
	
	
	
	/*std::string s(str);
	double number = atof(str);
	if(number == 0.0){
			if(str == "0.0" || str == "0")
				real = number; //str은 실수(actual number)
			else{
					int length = s.length();
					int starting_point_of_partition = -1;
					for(int i = length -1 ; i > -1; i++){
							if( str[i] == '+' || str[i] == '-'){
									starting_point_of_partition = i;
									break;
							}
					}
					if(starting_point_of_partition == -1 || starting_point_of_partition == 0){
							
							img = atof((s.substr(length-1)).c_str());
					}
					else{
							const char* front_part = (s.substr(0,starting_point_of_partition)).c_str();
							const char* back_part = (s.substr(starting_point_of_partition)).c_str();
							std::cout <<"back part is: "<<back_part<<std::endl;
							if(str[length - 1] == 'i')
								real = atof(front_part), img = atof(back_part);
							else
								real = atof(back_part), img = atof(front_part);
					}
			}
	}
	else
		real = number; //str is actual number
	std::cout << "real is : "<<real <<"image is : "<< img<<std::endl;
*/
}
Complex Complex::operator+(const char* str)const {
	Complex cstr(str);
	Complex temp(real + cstr.real, img + cstr.img);
	return temp;
}
Complex Complex::operator+(const Complex& c) const{
	Complex temp(real + c.real, img + c.img);
	return temp;
}
Complex Complex::operator-(const Complex& c) const{
	Complex temp(real - c.real, img - c.img);
	return temp;
}
Complex Complex::operator*(const Complex& c) const{
	Complex temp(real * c.real - img * c.img, real * c.img + img * c.real);
	return temp;
}
Complex Complex::operator/(const Complex& c) const{
	Complex temp( (real * c.real + img * c.img) / ((c.real) * (c.real) + (c.img)*(c.img)), ((img * c.real) - (c.img * real))/( c.real * c.real + c.img * c.img));
	return temp;
}
Complex& Complex::operator=(const Complex& c){
	real = c.real;
	img = c.img;
	return *this; 
}
Complex& Complex::operator+=(const Complex& c){
	(*this) = (*this) + c;
	//real += c.real;
	//img += c.img;
	return *this;
}
Complex& Complex::operator-=(const Complex& c){
	(*this) = (*this) - c;
//	real -= c.real;
//	img -= c.img;
	return *this;
}
Complex& Complex::operator*=(const Complex& c){
	(*this) = (*this) * c;
	//real = real * c.real - img * c.img;
	//img = real * c.img + img + c.real;
	return *this;
}
Complex& Complex::operator/=(const Complex& c){
	(*this) = (*this) / c;
	//real = ( real * c.real + img * c.img) / ( c.real * c.real + c.img * c.img);
	//img = ( c.real * img - real * c.img) / ( c.real * c.real + c.img * c.img);
	return *this;
}
int main() {
  /*Complex a(1.0, 2.0);
  Complex b(3.0, -2.0);
  Complex c(0.0, 0.0);
	c = a * b + a / b + a + b;
  c.println();
	Complex d = c; //이때는 대입연산자가 아닌 복사생성자가 호출된다 선언후 대입연산자를 사용하면 복사생성자가 호출되지 않는다.
	a += b;
	a.println();
	b /= a;
	b.println();*/
	Complex i("2i+3");
	Complex j("3+2i");
	Complex k("2i");
	Complex s("3");
	Complex t = i + j;
	Complex r = i + k;
	Complex a("-50");
	i.println();
	j.println();
	k.println();
	s.println();
	t.println();
	r.println();
	a.println();
	a = a + "-1.1+3i";
	a.println();
	return 0;
}
