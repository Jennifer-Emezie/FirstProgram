#include <iostream>
#include <cmath>
#include <string>
#include <fstream>
#include <cstdlib>
 
struct Point{
    double x;
    double y;
};
 
double distance_points(Point p1, Point p2){
    return std::sqrt(std::pow((p1.x - p2.x), 2) + std::pow((p1.y - p2.y), 2));
}
  struct Triangle{
    Point a,b,c; 
    };   

  double triangle_perimeter( Triangle t){
       
       return distance_points(t.a, t.b) + distance_points(t.a, t.c) + distance_points(t.c, t.b);
         
      } 
     

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

double triangle_perimeter(Triangle t );
  
  

std::cout << triangle_perimeter(t) << std::endl;

        
    }
 
  


