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
 
 
   
 
   
int s; 
    std:: cout << " Please enter the integer you would wish to search for"<< std:: endl;
std:: cin >> s; 
bool contained = false ;

  IntListNode* val;
    val = l;
    while(lit != NULL){

if (lit->val == s) {
    contained = true;
 return contained;
       
}
lit = lit->next;

}
if ( contained = true ){

std::cout << "This integert is contained within the list" <<std::endl;

}

  else {
   std::cout << "This integert is NOT contained within the list" <<std::endl;
      } 
      
         
  while(lit != NULL){
        tmp = lit->next;
        delete lit;
        lit = tmp;
    }
   
}


