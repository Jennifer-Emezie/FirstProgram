#include <iostream>#
double mpow(double x, int n){
    if(n == 0){
        return 1; // base case 
    }
    else{
        return x * mpow(x, n - 1); // recursive call
    }
}

int main (){

double n,t;
int p; 
    std::cout << "Please type your indicies "<< std::endl; 
    std::cin >> n; 
     std::cout << "to the power of " << std::endl; 
     std::cin >> p; 

     t= mpow(n,p);
        std::cout << "= " << t << std::endl; 
}
