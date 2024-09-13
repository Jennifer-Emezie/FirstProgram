#include <iostream>
#include <cmath>
#include <string>

struct complex{
    double realPart;
    double imagPart;
};

std::string complex_form (complex c1){
    if( c1.imagPart == 0){
 return std::to_string (c1.realPart);

    }

    else if ( c1.imagPart <0) {

        return std::to_string( c1.realPart)  + " " + std :: to_string(c1.imagPart) + "i" ;

    }


else{
    return  std::to_string( c1.realPart) + " + " + std :: to_string(c1.imagPart) + "i" ;

}
}
bool quadsolve(double a, double b, double c, complex& x1, complex& x2){
 
    bool realsol;
    double delta = b*b - 4 * a * c;
 
    if(delta < 0){
        realsol = false;
        x1.realPart = -b/(2*a);
        x1.imagPart = std::sqrt (-delta)/(2*a);   
        x2.realPart = -b/(2*a);
        x2.imagPart = -std::sqrt (-delta)/(2*a);   
         }
    else{
 
        realsol = true;
        x1.realPart = (-b + std::sqrt(delta)) / (2 * a);
        x2.realPart = (-b - std::sqrt(delta)) / (2 * a);
 
        x1.imagPart =0;
        x2.imagPart =0;
 
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
 
   complex s1, s2;
    // we pass these variables uninitialised to the function
    // because the values will be provided in output 
    // by the function
 
    if(quadsolve(a, b, c, s1, s2)){
        std::cout << "the solutions are:" << std::endl;

        std::string complex_form(complex s1);
        std::string complex_form(complex s2);
        std::cout << complex_form(s1) << std::endl;
        std::cout << complex_form(s2) << std::endl;
    }
    else{
       std::cout << "the solutions are:" << std::endl;
         std::string complex_form(complex s1);
        std::string complex_form(complex s2);
        std::cout << complex_form(s1) << std::endl;
        std::cout << complex_form(s2) << std::endl;
 
}
}