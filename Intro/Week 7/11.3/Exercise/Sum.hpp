#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

class Point {

    public:
    
 Point(double ix, double iy) : x(ix), y(iy) {
      
  }
std::string to_string() const {
      return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
  }
 
  double distance(Point p) const {
      return std::sqrt(std::pow((x - p.x), 2) + std::pow((y - p.y), 2));
  }

private :

    double x;
    double y;

};

double sum_distances_points(const std::vector<Point>& pv){
    if (pv.size() < 2) {
        return 0;
    }
    double sum = 0;
    for (int i = 0; i < pv.size() - 1; ++i) {
        
       sum = sum + pv[i + 1].distance (pv[i]);
      
    }
    return sum;
}
 
int main(){
    std::ifstream infile;
    infile.open("points.txt");
 
    if(!infile.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }
 
    std::vector<Point> points;
 
    double inx, iny;
 
    while(infile >> inx >> iny){
        Point p1(inx, iny);
       points.push_back(p1);
    } 
 
    infile.close();
 
    std::cout << sum_distances_points(points) << std::endl;
 
}