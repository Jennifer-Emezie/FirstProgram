#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>
 
struct Point{
    double x;
    double y;
 
    std::string to_s() const {
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
    }
 
    double distance(Point p) const {
        return std::sqrt(std::pow((x - p.x), 2) + std::pow((y - p.y), 2));
    }
}; 
  struct Triangle{
    Point a,b,c; 
      

  double t_perimeter( Triangle t) const{
       
       return t.b.distance(t.a) + t.c.distance(t.a) + t.b.distance(t.c);
         
      } 
     
 };
int main(){
 
    Point pa, pb, pc;
 
    std::cout << "Please enter the first coordinate of your triangle" << std::endl;
    std::cin >> pa.x >> pa.y;
 
    std::cout << "Please enter the second coordinate of your triangle" << std::endl;
    std::cin >> pb.x >> pb.y;

    std::cout << "Please enter the third coordinate of your triangle" << std::endl;
    std::cin >> pc.x >> pc.y;

  Triangle t;
  t.a = pa;
  t.b = pb;
  t.c = pc;

double perimeter= t.t_perimeter(t);
  
  

std::cout << perimeter << std::endl;

        
    }
 
  


