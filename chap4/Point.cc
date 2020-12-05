#include <iostream>
#include <cmath>

class Point {
  int x, y;
 public:
  Point(int pos_x, int pos_y);
  int getX() const;
  int getY() const;
};

Point::Point(int pos_x, int pos_y){
  x = pos_x;
  y = pos_y;
}
int Point::getX() const{
  return x;
}
int Point::getY() const{
  return y;
}

class Geometry{
  Point* point_array[100];
  int iCount;
 public:
  Geometry(Point **point_list);
  Geometry(); // = default;

  void AddPoint(const Point &point);

  void PrintDistance();
  
  void PrintNumMeets();
};

Geometry::Geometry(Point **point_list){
  //point_array = point_list;
  iCount = 0;
  while(*point_list != nullptr){
      point_array[iCount] = *point_list; //추가된것
      iCount++;
      point_list++;//만약 point_list가 plus됐다고해서 .point_array가 영향을 받지 않기 때문에 괜찮을듯.
  }
}

Geometry::Geometry(){
  iCount = 0;
  *point_array = nullptr;
}

void Geometry::AddPoint(const Point &point){
  //correct point_array[iCount] = new Point(point);
  Point* pt= new Point(point.getX(),point.getY());
  point_array[iCount] = pt; 
  //error point_array[iCount] = point;
  iCount++;
}

void Geometry::PrintDistance(){
  for(int i = 0; i < iCount-1;i++){
      int distance_x = point_array[i]->getX() - point_array[i+1]->getX();
      int distance_y = point_array[i]->getY() - point_array[i+1]->getY();
      
      std::cout<<i<<"번쨰와 "<<i+1<<"의 거리는: "<< double(sqrt(pow(distance_x,2) + pow(distance_y,2))) << std::endl;
  }
}

int main(){
  Point x(3,5);
  Point y(4,7);
  Point z(9,10);
  Point* arr[3] = { &x, &y, &z};
  Geometry g(arr);
  /*g.AddPoint(x);
  g.AddPoint(y);
  g.AddPoint(z);*/
  g.PrintDistance();
  return 0;
}

