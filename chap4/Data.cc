#include <iostream>

class Date{
  int year_;
  int month_;
  int day_;
  int month_days[13] ={0,31,0,31,30,31,30,31,31,30,31,30,31};
public:
  Date(int year, int month, int day){
    year_ = year;
    month_ = month;
    day_ = day;
  }
  void SetDate(int year, int month, int date){
    year_ = year;
    month_ = month;
    day_ = date;
    SetLeapYear();
  }
  void AddDay(int inc){
    int added_day = day_ + inc;
    while(month_days[month_] < added_day){
        added_day -= month_days[month_];
        AddMonth(1);
    }
    day_ = added_day;
  }
  void AddMonth(int inc){
    int added_month = month_ + inc;
    while(added_month > 12){
        added_month -=12;
        AddYear(1);
    }
    month_ = added_month;
  }
  void AddYear(int inc){
    year_ += inc;
    SetLeapYear();
  }
  void SetLeapYear(){
    if(year_%4 ==0)
        month_days[2] = 29;
    else
        month_days[2] = 28;
  }
  void ShowDate(){
    std::cout<<year_<<"-"<<month_<<"-"<<day_<<std::endl;
  }
};

int main(){
  Date data(2011,11,1);
  //data.SetDate(2018, 03, 25);
  data.ShowDate();
  data.AddDay(7);
  data.ShowDate();
  data.AddMonth(5);
  data.ShowDate();
  data.AddYear(1);
  data.ShowDate();
  return 0;
}

