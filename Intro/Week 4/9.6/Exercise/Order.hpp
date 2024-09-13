#include <iostream>
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

ListNode* ordered_insertion_list(list_t e, ListNode* l){
    if(l == NULL){
        return cons_list(e, l);
    }
    else if(e < l->val){
        return cons_list(e, l);
    }
    else{
        l->next=ordered_insertion_list(e, l->next);
        return l;
    }
}

ListNode* ordered_copy_list(ListNode* l){

int min = l->val;
int n = length_list_rec(l);
ListNode* tmp = NULL; 
ListNode* copy = NULL;

 while(l != NULL){
if (l->val < min){
    min = l->val;
} 

tmp = cons_list(l->val, tmp);
 l = l->next;

    }
copy = cons_list(min, copy);


    while (tmp != NULL ){
        if (tmp-> val > min){

copy = ordered_insertion_list(tmp->val, copy);
}
        tmp = tmp->next;
    
    
    }

return copy;

}
int main () {

     ListNode* l = NULL;
    
 
    l = cons_list(2, l);

    l = cons_list(1, l);
    l = cons_list(3, l);
        l = cons_list(6, l);

            l = cons_list(4, l);
                      l = cons_list(5, l); 
                       
 
    print_list_rec(l);
    l =ordered_copy_list(l);
    std::cout << " "<<std::endl;
    print_list_rec(l);
deallocate_list_rec(l);

}