#include <iostream>
 
struct IntListNode{
    int val;
    IntListNode* next;
};
 
int main(){
    IntListNode* l;
    l = NULL; 
 
    IntListNode* tmp;

    int n , j;
 
std:: cout << " please enter your desired length of your list" << std:: endl; 
std:: cin >> n;
std:: cout << " Now enter your list :"<< std::endl; 

for (int i = 0; i < n; i++) { 

std:: cin >> j ; 
    tmp = new IntListNode;
    tmp->val = j;
    tmp->next = l;
 
    l = tmp;
}

std:: cout<< " Your list is :"<< std::endl;
     IntListNode* lit;
    lit = l;

    while(lit != NULL){
        std::cout << lit->val << std::endl;
        lit = lit->next;
    }
 
    lit = l;
 
    while(lit != NULL){
        tmp = lit->next;
        delete lit;
        lit = tmp;
    }
}