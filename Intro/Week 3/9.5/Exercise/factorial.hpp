#include <iostream>
double mpow(double x, int n){
    if(n == 0){
        return 1; // base case 
    }
    else{
        return x * mpow(x, n - 1); // recursive call
    }
}

int mfact(int n){

     if (n <=0){
        return 1;
    }

    else{
      return n*mfact(n-1);  

    }

}

int main (){

double n,t;
int p; 
    std::cout << "Factorial of "<< std::endl; 
    std::cin >> n; 
    
     t= mfact(n);
        std::cout << "= " << t << std::endl; 

        
}
