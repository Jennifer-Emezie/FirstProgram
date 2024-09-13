#include <iostream>
#include <fstream>
typedef int tree_t;
 
struct TreeNode{
    tree_t val;
    TreeNode* left;
    TreeNode* right;
};
 
TreeNode* cons_tree(tree_t e, TreeNode* l, TreeNode* r){
    TreeNode* tmp;
    tmp = new TreeNode;
    tmp->val = e;
    tmp->left = l;
    tmp->right = r;
    return tmp;
}
 
TreeNode* ordered_insertion_tree(tree_t e, TreeNode* t){
    if(t == NULL){
        return cons_tree(e, NULL, NULL);
    }
    else if(e < t->val){
        t->left = ordered_insertion_tree(e, t->left);
        return t;
    }
    else{
        t->right = ordered_insertion_tree(e, t->right);
        return t;
    }
}
 
void print_tree(TreeNode* t){
    if(t != NULL){
        print_tree(t->left);
        std::cout << t->val << std::endl;
        print_tree(t->right);
    }
}
 
void deallocate_tree(TreeNode* t){
    if(t != NULL){
        deallocate_tree(t->left);
        deallocate_tree(t->right);
        delete t;
    }
}

bool search_ordered_tree(tree_t e, TreeNode* t) {

if (t==NULL){

return false;
}

if (t-> val == e ){
    return true;
}

if ( e<t->val){
t->val = search_ordered_tree(e,t ->left);
    }
    else{
t->val = search_ordered_tree(e, t->right);     
    }
    
}

TreeNode* min_element_tree(TreeNode* t){
    TreeNode* min = NULL;
while (t->left != NULL){
    t= t->left;
}

min =ordered_insertion_tree(t->val, min);

return min;

}


 
int main(){
    TreeNode* t;
    t = NULL;
std::ifstream infile; 
    infile.open("tree.txt");

 int tmp;
    while(infile >> tmp){
      
       t = ordered_insertion_tree(tmp, t);  
    }   
 
    print_tree(t);

    TreeNode* min = min_element_tree(t);

    std::cout<< "The minimum value within the list is:" <<std::endl;
print_tree(min);


 
    deallocate_tree(t);
    deallocate_tree(min);
 
}