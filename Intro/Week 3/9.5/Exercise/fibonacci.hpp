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

int fib(int n){
    int f;
     if (n ==0){
        return 0;
    }
else if (n ==1){
    return 1;
}
    else{

        f= fib(n-1)+ fib(n-2);
      return f;  

    }

}

int main (){

double n,t;
int p; 
    std::cout << "Fibonacci of "<< std::endl; 
    std::cin >> n; 
    
     t= fib(n);
        std::cout << "= " << t << std::endl; 

        
}
