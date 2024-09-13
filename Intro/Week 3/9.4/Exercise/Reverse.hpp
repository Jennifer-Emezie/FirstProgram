#include <iostream>
#include <fstream>
#include <list>
 
typedef int list_t;

  
  
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

ListNode* reversed_copy_list(ListNode* l){
ListNode* tmp;
 while(l != NULL){
    tmp= cons_list(l->val, tmp);
        l = l->next;
    }

return tmp;
}

 
int main(){
    ListNode* l = NULL;
std::ifstream infile; 
    infile.open("intlist.txt");

  int tmp,s,n;
bool all = true;
    while(infile >> tmp){
      
       l = cons_list(tmp, l);  
    }   

    infile.close();

    print_list(l);
 l = reversed_copy_list(l);

print_list(l);


 deallocate_list(l);

}