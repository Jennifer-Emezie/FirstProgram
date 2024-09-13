#include <iostream>
 
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
 
 
 
void print_list_rec(ListNode* l){
    if(l != NULL){
        std::cout << l->val << std::endl;
        // we print the first element
        print_list_rec(l->next);
        // then the rest of the list
    }
}
 
void deallocate_list_rec(ListNode* l){
    ListNode* tmp;
 
    if(l != NULL){
        tmp = l->next;
        delete l;
        deallocate_list_rec(tmp);
    }
}

 int length_list_rec(ListNode* l){
    int t;
    while (l != NULL){
        t = 1+ length_list_rec(l->next);
        
        if ( t == 0 ){
            return 0;
        }
        else {
return t;
        }
    }

 }

 bool search_list_rec(list_t e, ListNode* l){
// should it be != 0
while (l != NULL && length_list_rec(l) == 0){

    if (l->val == e){
        return true;
    }
 
  search_list_rec(e, l->next);
} 
return false;

 }

int main(){
    ListNode* l = NULL;
    int e;
 

    l = cons_list(2, l);
    l = cons_list(3, l);
 
    print_list_rec(l);

std:: cout << " please type the integer you wish to find " << std::endl;
std::cin >> e;

 bool search = search_list_rec(e,l);
std::cout << search << std::endl;
    deallocate_list_rec(l);
}