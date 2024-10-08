#include <iostream>
#include <cmath>
// for the square root
 
bool quadsolve(double a, double b, double c, double& x1, double& x2){
 
    bool realsol;
    double delta = b*b - 4 * a * c;
 
    if(delta < 0){
        realsol = false;
    }
    else{
 
        realsol = true;
        x1 = (-b + std::sqrt(delta)) / (2 * a);
        x2 = (-b - std::sqrt(delta)) / (2 * a);
 
        // function sqrt computes the square root
        // more legible and sometimes more efficient
        // than using e.g. std::pow(delta, 0.5)
 
    }
 
    return realsol;
}
 
int main(){
 
    double a, b, c;
    // it is just a coincidence that these variables are named
    // like the function parameters, they could have a different name
 
    std::cout << "this program finds the real solutions" << std::endl;
    std::cout << "of an equation of the form ax^2 + bx + c = 0" << std::endl;
    std::cout << "please enter the coefficients a, b, c:" << std::endl;
 
    std::cin >> a >> b >> c;
 
    double s1, s2;
    // we pass these variables uninitialised to the function
    // because the values will be provided in output 
    // by the function
 
    if(quadsolve(a, b, c, s1, s2)){
        std::cout << "the solutions are:" << std::endl;
        std::cout << s1 << std::endl;
        std::cout << s2 << std::endl;
    }
    else{
        std::cout << "there are no real solutions" << std::endl;
    }
 
}