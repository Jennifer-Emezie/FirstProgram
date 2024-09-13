#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>

struct Contact { 

std::string first_name, surname, email, number;

};


int search_contact(const std::vector<Contact>& contacts, std::string first_name, std::string surname){
    for(int i = 0; i < contacts.size(); i++){

        if(contacts[i].first_name ==first_name && contacts[i].surname == surname){
            return i;
        }
    
}
}
 

 std::string full_contact (Contact c){

    return "Your contact is :" + c.first_name + " " + c.surname + " " + c.email + " "+ c.number;;
}



int main(){ 
    
    std::vector<Contact> vcontact;

    std::ifstream infile;
    infile.open("contacts.txt");
 
    if(!infile.is_open()){
        std::cout << "error opening file" << std::endl;
        return EXIT_FAILURE;
    }
 
   
   Contact tmp;
 
    while(infile >> tmp.first_name >> tmp.surname >> tmp.email >> tmp.number){

        vcontact.push_back(tmp);
    }
 
    infile.close();

std ::cout << " Please enter the first name and surname of the contact you wish to find :" << std ::endl; 

std:: string first_name, surname;
std:: cin >> first_name >> surname;

int i = search_contact(vcontact, first_name, surname);
 
 Contact c = vcontact[i];



        std::cout << full_contact (c) << std::endl;

 
}

 
    
