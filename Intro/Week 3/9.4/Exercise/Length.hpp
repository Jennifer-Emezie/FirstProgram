#include <iostream>
#include <fstream>
 
typedef std::string list_t;
  
struct ListNode{
    list_t val;
    ListNode* next;
};
 
ListNode* cons_list(list_t e, ListNode* l){
    ListNode* tmp;
 
    tmp = new ListNode;
 
    tmp->val = e;
    tmp->next = l;
 
    return tmp;
}
 
void print_list(ListNode* l){
    while(l != NULL){
        std::cout << l->val << std::endl;
        l = l->next;
    }
}
 
void deallocate_list(ListNode* l){
    ListNode* tmp;
 
    while(l != NULL){
        tmp = l->next;
        delete l;
        l = tmp;
    }
}

int length_list(ListNode* l){
    int i=0; 
    while(l != NULL){
       
               l = l->next;

        i++;
    }
    return i;

}

 
int main(){
    ListNode* l = NULL;
std::ifstream infile; 
    infile.open("stringlist.txt");

  std::string tmp;
 int s;
    while(infile >> tmp){
      
       l = cons_list(tmp, l);  
    }   
 
    s = length_list(l);
    std::cout << s << std::endl;
    deallocate_list(l);
}