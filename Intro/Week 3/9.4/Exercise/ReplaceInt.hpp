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

bool search_list(list_t e, ListNode* l){
 
    while(l != NULL ){
        

            if (l->val == e) {
                return true;
                
            }
            l = l->next;

        

    }
return false;


}

 bool replace_list(list_t e, list_t n, ListNode* l, bool all) {
    
    int i= 0;

    if (all== false){
    while((l != NULL)  && (i<=0)){
        

            if ((l->val == e) ) {
               (*l).val = 'n';
               i++;
                
            }
            l = l->next;

        

    }


    }

    else {
          while(l != NULL ){
        

            if (l->val == e) {
               (*l).val = 'n';
                i++;
                             
            }
            l = l->next;

        

    }

    }

if (i>0){
    return true;
}

else{
    return false;
}

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
 
 std::cout << "Please input the integer you wish to search for :" <<std::endl;
 std::cin >> s;

 bool result = replace_list(s,n,l,all);

 

std::cout << result <<std::endl;
print_list(l);


 deallocate_list(l);

}