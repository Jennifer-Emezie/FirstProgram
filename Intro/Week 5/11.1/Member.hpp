#include <iostream>
#include <cmath>
#include <string>
 
struct Point{
    double x;
    double y;
 
    // since this is now a member function of Point, we can just call it to_s()
    // note that now the function doesn't have an input parameter because it will work 
    // on the Point variable on which it is called 
 
    std::string to_s(){
        return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
        // here x and y are the x and y of the Point variable on which the function is called
    }
 
    // since this is now a member function of Point, we can just call it distance()
    // note that now the function has only one parameter because it will compute the distance
    // between the Point variable on which it is called and parameter p
 
    double distance(Point p){
        return std::sqrt(std::pow((x - p.x), 2) + std::pow((y - p.y), 2));
        // here x and y are the x and y of the Point variable on which the function is called
    }
}; 
 
int main(){
    Point pa, pb;
 
    std::cout << "enter coordinates for the first point" << std::endl;
    std::cin >> pa.x >> pa.y;
 
    std::cout << "enter coordinates for the second point" << std::endl;
    std::cin >> pb.x >> pb.y;
 
    std::cout << "you entered the following points:" << std::endl;
    std::cout << pa.to_s() << std::endl;
    std::cout << pb.to_s() << std::endl;
 
    std::cout << "their distance is: " << pa.distance(pb) << std::endl;
}