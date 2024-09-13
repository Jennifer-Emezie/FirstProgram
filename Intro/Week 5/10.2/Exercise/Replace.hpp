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

int count_nodes_tree(TreeNode* t){
     
if (t ==NULL){
    return 0;
}

int l = count_nodes_tree(t->left);
int r = count_nodes_tree(t->right);

return 1+ l+ r;
   
}

 int count_leaves_tree(TreeNode* t){
    if (t==NULL){
        return 0;
    }
    if (t ->left ==NULL && t -> right == NULL){
        return 1;
    }
    else {
        return count_leaves_tree(t->left) + count_leaves_tree(t->right);
    }
 }

  int count_occurrences_tree(tree_t e, TreeNode* t){
     if (t==NULL){
        return 0;
    }
  if (t->val==e){
        return 1+count_occurrences_tree(e,t->right) + count_occurrences_tree(e,t->left);
    }
    if (e<t->val){
       return count_occurrences_tree(e,t->left);
    }

    else{
        return count_occurrences_tree(e,t->right);
    }

  }

  int replace_tree(tree_t e, tree_t r, TreeNode* t, int n) {
    int i=0;
   
     if (t==NULL){
        return 0;
    }
   
  if (t->val==e && i<n){ 
    
    (*t).val = r;
    i++;
     return i; 
    } 
    if (e<t->val ){
       return replace_tree(e,r,t->left, n-i);
    }

    else{

        return replace_tree(e,r,t->right, n-i) ;
    }
        
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
int e,r,n;
    std::cout << "Number you wish to replace" << std::endl;
std :: cin >> e;
std::cout << "With:" << std::endl;
std :: cin >> r;
std::cout << "How many times:" << std::endl;
std :: cin >> n;
    int c= replace_tree(e,r,t, n);

    std::cout<< "The this is how many times " << e << " was replaced: " << c << std::endl;

std::cout << "The new list is:" << std::endl;
print_tree(t);
 
    deallocate_tree(t);
   
 
}