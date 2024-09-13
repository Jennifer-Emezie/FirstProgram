#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

struct TreeNode;
struct EdgeNode;

typedef std::string tree_t;

struct EdgeNode{
    tree_t val;
    TreeNode* subtree;
    EdgeNode* next;
};

struct TreeNode
{
    tree_t val;
    EdgeNode *subtree_l;
};

class A3Tree { 

private: 
TreeNode* t;
int node_counter;   

 int count_leaf_nodes(TreeNode* t) const {// same code as last time
       
    if (t == NULL)
    {
        return 0;
    }

    int c = 0;

    for (EdgeNode *it = t->subtree_l; it != NULL; it = it->next) 
    
    {
        //Pointer 'it' looking at the highest level away from the root. 
    //This contains all the leaves. 
    //As you jump from one leaf to another add 1 till it is NULL. 

        c = count_leaf_nodes(it->subtree) + c;
    }

    return (t->subtree_l == NULL) + c; // return 1+ counter from other leaves
}

// These are all the same code from assesment 2.
TreeNode *allocate_tree_node(tree_t e)
{
    TreeNode *tmp = new TreeNode;
    tmp->val = e;
    tmp->subtree_l = NULL;
    return tmp;
}

EdgeNode *cons_edge_node(TreeNode *t, EdgeNode *subtree_l, tree_t val)
{
    EdgeNode *tmp = new EdgeNode;
    tmp->subtree = t;
    tmp->next = subtree_l;
    tmp->val = val; // Now an added edge value.
    return tmp;
}

void print_tree(TreeNode *t)
{
    if (t != NULL)
    {
        EdgeNode *it = t->subtree_l;
        while (it != NULL)
        {
            print_tree(it->subtree);
            it = it->next;
        }
        std::cout << t->val << std::endl;
    }
}

TreeNode *build_tree_root(tree_t e)
{
    return allocate_tree_node(e);
}

TreeNode *find_node(tree_t e, TreeNode *t)
{

    if (t == NULL)
    {
        return t;
    }

    if (t->val == e)
    {
        return t;
    }
    for (EdgeNode *it = t->subtree_l; it != NULL; it = it->next)
    {
        TreeNode *adress = find_node(e, it->subtree);
        if (adress != NULL)
        {
            return adress;
        }
        return NULL;
    }
}

void add_tree_node(tree_t s, tree_t d, TreeNode *t)
{
    TreeNode *parent = find_node(s, t);

    if (parent == NULL)
    {
        return;
}
        TreeNode *child = allocate_tree_node(d);

        parent->subtree_l = cons_edge_node(child, parent->subtree_l,d);
    
}


void deallocate_tree(TreeNode *t)
{
    if (t != NULL)
    {
        EdgeNode *it = t->subtree_l;
        while (it != NULL)
        {
            deallocate_tree(it->subtree);
            EdgeNode *prev = it;
            it = it->next;
            delete prev;
        }
        delete t;
    }
}

public:

//this function should turn our vector string into a tree structure
A3Tree(const std::vector<std::vector<std::string>>& input) {
    t = build_tree_root(input[0][0]); // Create the root node with the first value

// First look at the rows of the table (selecting each string vector in vector).
    for (int i = 0; i < input.size(); i++) { 
        const std::vector<std::string>& values = input[i];
        TreeNode* currentNode = t;
        bool edgeFound = false;
//going through each element in selected string vector.
        for (int j = 0; j < values.size() && edgeFound==false; j++) {
            const std::string& value = values[j];
            EdgeNode* edge = currentNode->subtree_l;

//Checking to see if node already exists.
            while (edge != NULL) {
                if (edge->val == value) {
                    currentNode = edge->subtree;
                    edgeFound = true;
        
                }   
                edge = edge->next;    
            } 
//if not create a new one.
            if (edgeFound==false) {
                TreeNode* newNode = allocate_tree_node(value);
                currentNode->subtree_l = cons_edge_node(newNode, currentNode->subtree_l, value);
                currentNode = newNode;
                node_counter++;
            }  
            
            
        }
    }
}

std::string query(const std::vector<std::string>& find) const {
        TreeNode* currentNode = t; //start with the root node check 'find' vector value and see if matches.
       

        

        for (int i= 0; i<find.size(); i++) {
            EdgeNode* edge = currentNode->subtree_l;
    
        bool found =false; // this will tell us if a match is found.
            while (edge != NULL) {
                if (edge->val == find[i]) {
                    currentNode = edge->subtree;
found = true;
                    // exit loop when a match is found 
                }

                edge = edge->next; //check the next edge node
            }

            if (found == false) {
                return " ";  // If value not found, return empty string 
            }
        }

        return currentNode->val;
    }



int node_count () const {
    return node_counter; 
}

int leaf_node_count () const {
    return count_leaf_nodes(t); // calls back to private function to count leaves.
}

};

int main(){
 
    // direct initialisation of a vector
    // in this case it's a vector containing vectors
    // each of which contains words (std::string)
    std::vector<std::vector<std::string>> input
    {
        {"temperature", "rain", "wind", "quality"},
        {"high", "yes", "light", "acceptable"},
        {"low", "yes", "light", "acceptable"},
        {"low", "no", "moderate", "good"},
        {"high", "yes", "strong", "poor"},
        {"high", "yes", "moderate", "acceptable"},
        {"high", "no", "moderate", "good"},
        {"low", "yes", "strong", "poor"},
        {"high", "no", "light", "good"},
        {"low", "yes", "moderate", "poor"},
        {"high", "no", "strong", "poor"}
    };
 
    A3Tree t(input);
 
    // direct initialisation of a vector:
    std::vector<std::string> q{"low", "yes", "strong"};
 
    std::cout << t.query(q) << std::endl;
    // this should print: poor
 
    // assigning new content overwriting the previous content:
    q =  {"high", "yes", "moderate"};
 
    std::cout << t.query(q) << std::endl;
    // this should print: acceptable
 
    std::cout << t.node_count() << std::endl;
    // this depends on the actual tree generated,
    // if we consider the tree in the example which
    // has wind in the root node this should print: 10
 
    std::cout << t.leaf_node_count() << std::endl;
    // this depends on the actual tree generated,
    // if we consider the tree in the example which
    // has wind in the root node this should print: 6

    std::cout << print_tree(t)<< std::endl;

  
 
}