#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

class Contact { 

public:

Contact (std::string x, std::string y, std::string z, std::string a) {
x= first_name;
y= surname;
z=email;
a= number;
}

std::string fn() const { 
    return first_name;
}

std::string s() const { 
    return surname;
}

std::string e() const { 
    return email;
}

std::string n() const { 
    return number;
} 


private:

std::string first_name;
std::string surname;
std::string email;
std::string number;
};

int search_contact(const std::vector<Contact>& contacts, std::string first_name, std::string surname){
    for(int i = 0; i < contacts.size(); i++){

        if(contacts[i].fn() ==first_name && contacts[i].s() == surname){
            return i;
        }
    
}
}
std::string full_contact (const Contact& c){

    return "Your contact is :" + c.fn () + " " + c.s() + " " + c.e() + " "+ c.n();
}


int main(){ 
    
    std::vector<Contact> vcontact;

    std::ifstream infile;
    infile.open("contacts.txt");
 
    if(!infile.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }
 
 std::string fn;
std::string s;
std::string e;
std::string n;
   
   Contact tmp(fn, s,e,n);
 
    while(infile >> fn >> s >> e >> n){

        vcontact.push_back(tmp);
    }
 
    infile.close();

std ::cout << " Please enter the first name and surname of the contact you wish to find :" << std ::endl; 

std:: string x,y;
std:: cin >> x >> y;

vcontact[search_contact(vcontact,x,y)];

 


        std::cout << full_contact(vcontact[0]) << std::endl;

 
}

 
    
