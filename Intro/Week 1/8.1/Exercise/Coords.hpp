#include <iostream>
#include <cmath>
#include <string>

 
struct Point{
    double x;
    double y;
}; 
 
double distance_points(Point p1, Point p2){
    return std::sqrt(std::pow((p1.x - p2.x), 2) + std::pow((p1.y - p2.y), 2));
}
 
std::string point_to_s(Point p){
    return "(" + std::to_string(p.x) + ", " + std::to_string(p.y) + ")";
}

int main(){
    Point pa, pb;
 
    std::cout << "enter coordinates for the first point" << std::endl;
    std::cin >> pa.x >> pa.y;
 
    std::cout << "enter coordinates for the second point" << std::endl;
    std::cin >> pb.x >> pb.y;
 
    std::cout << "you entered the following points:" << std::endl;
 
 std::string point_to_s(Point pa);
 std::string point_to_s(Point pb);

 std::cout << point_to_s(pa) << std::endl;
 std::cout << point_to_s(pb) << std::endl;

    
    std::cout << "their distance is: " << distance_points(pa, pb) << std::endl;
}