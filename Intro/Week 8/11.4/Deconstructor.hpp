#include <iostream>
 
class SomeClass{
 
public:
 
    SomeClass(int idinput) : id(idinput) { 
      std::cout << "object with id " << id << " instantiated" << std::endl;
    }
 
    // the destructor
    ~SomeClass(){
        std::cout << "object with id " << id << " going out of scope" << std::endl;
    }
 
private:
 
    int id;
 
};
 
void f(){
    SomeClass s(1);
}
 
int main(){
    SomeClass s(2);
 
    SomeClass* sp;
    sp = new SomeClass(3); 
    // with dynamic memory allocation
 
    f();
    delete sp;
}