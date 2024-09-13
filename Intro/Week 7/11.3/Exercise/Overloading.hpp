#include <iostream>
class Counter{
 
public:
 
    Counter(int x){
        c=x;
    }
 
    void inc(){
        c++;
    }
 
    int get_count() const {
        return c;
    }
 
private:
 
    int c;
 
};
int main(){
 
    Counter c1(6);
 
    std::cout << c1.get_count() << std::endl;
 
    c1.inc();
    // ok because member function inc() is public
 
    std::cout << c1.get_count() << std::endl;
 
    // c1.c = -2;
    // this would not compile because the c member data is private
 
} 
