#include <iostream>
 
int main(){
    double a;
    double* pi; 
   
 
    pi = &a;
 
    std::cout << &a << std::endl;
    std::cout << pi << std::endl;
 
}