#include <iostream>

class Animal{                   
 private:
  int food;
  int weight;
  
 public:
  void set_animal(int _food, int _weight){
    food = _food;
    weight = _weight;
  }
  void increase_food(int inc){
    food += inc;
    weight += (inc/3);
  }
  void view_stat(){
    std::cout << "this animal's food: "<< food << std::endl;
    std::cout << "this animal's weight: "<< weight << std::endl;
  }
};

int main(){
  Animal animal;
  animal.set_animal(100,50);
  animal.view_stat();
  return 0;
}
