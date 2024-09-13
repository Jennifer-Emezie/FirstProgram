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

ListNode* ordered_copy_list(ListNode* l){

    ListNode* c = NULL;


while (l != NULL){


ListNode* tmp;
 while(l != NULL){
    tmp= ordered_insertion_list(l->val, tmp);
        l = l->next;
    }

return tmp;

 
}





}

int main () {

     ListNode* l = NULL;
    
 
    l = cons_list(2, l);
    l = cons_list(3, l);
        l = cons_list(5, l); 
        l = cons_list(6, l);
            l = cons_list(7, l);
                    l = cons_list(9, l);
                       
 
    print_list_rec(l);
    l =ordered_insertion_list(l);
    print_list_rec(l);
deallocate_list_rec(l);

}