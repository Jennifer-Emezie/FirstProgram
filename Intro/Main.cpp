#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

struct TreeNode;
struct EdgeNode;

typedef std::string tree_t;

struct EdgeNode
{
    tree_t val;
    TreeNode *subtree;
    EdgeNode *next;
};

struct TreeNode
{
    tree_t val;
    EdgeNode *subtree_l;
};

class A3Tree
{

private:
    TreeNode *t;
    int total_node_counter;
    int node_counter;
    int edge_counter;

    int count_leaf_nodes(TreeNode *t) const
    { // same code as last time

        if (t == NULL)
        {
            return 0;
        }

        int c = 0;

        for (EdgeNode *it = t->subtree_l; it != NULL; it = it->next)

        {
            // Pointer 'it' looking at the highest level away from the root.
            // This contains all the leaves.
            // As you jump from one leaf to another add 1 till it is NULL.

            c = count_leaf_nodes(it->subtree) + c;
        }

        return (t->subtree_l == NULL) + c;
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

    void build_tree(const std::vector<std::vector<std::string>> &input)
    {
        t = build_tree_root(""); // Create the root node with an empty value

        for (int i = 0; i < input.size(); i++)
        {
            const std::vector<std::string> &values = input[i]; // Starting with the rows of the input
            TreeNode *currentNode = t;

            for (int j = 0; j < values.size(); j++) // each element in selected string
            {
                bool edgeFound = false;
                const std::string &value = values[j];
                EdgeNode *edge = currentNode->subtree_l;

                // This is to check if the current value is already an edge
                while (edge != NULL && edgeFound == false)
                {
                    if (edge->val == value)
                    {
                        currentNode = edge->subtree;
                        edgeFound = true;
                    }
                    edge = edge->next;
                }

                // If the edge is not found, create a new subtree
                if (edgeFound == false)
                {
                    TreeNode *newNode = allocate_tree_node(value);
                    currentNode->subtree_l = cons_edge_node(newNode, currentNode->subtree_l, value);
                    currentNode = newNode;
                    total_node_counter++;
                    edge_counter++;
                }
            }
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
            TreeNode *address = find_node(e, it->subtree);
            if (address != NULL)
            {
                return address;
            }
        }

        return NULL;
    }

    void add_tree_node(tree_t s, tree_t d, TreeNode *t)
    {
        TreeNode *parent = find_node(s, t);

        if (parent == NULL)
        {
            return;
        }
        TreeNode *child = allocate_tree_node(d);

        parent->subtree_l = cons_edge_node(child, parent->subtree_l, d);
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
    // this function should turn our vector string into a tree structure
    A3Tree(const std::vector<std::vector<std::string>> &input)
    {
        edge_counter = 0;
        total_node_counter = 1; // due to root node
        build_tree(input);
    }

    std::string query(const std::vector<std::string> &find) const
    {
        TreeNode *currentNode = t; // start with the root node check 'find' vector value and see if matches.

        bool found = false; // this will tell us if a match is found.

        for (int i = 0; i < find.size(); i++)
        {
            EdgeNode *edge = currentNode->subtree_l; // this is a marker to see where we are and where to stop.
            found = false;
            while (edge != NULL && found == false)
            {
                if (edge->val == find[i])
                {

                    // When match is found, found is true and move to next value
                    currentNode = edge->subtree;
                    found = true;
                    // exit loop when a match is found
                }

                edge = edge->next; // check to see if the next value
            }

            if (found == false)
            {
                return " "; // If value not found, return empty string
            }
        }

        EdgeNode *edge = currentNode->subtree_l; // New edge node containing last node that matches.
        std::string nextSubtreeNode = "";        // Output will be empty string if nothing is next (next Subtree = NULL)

        while (edge != NULL)
        {
            nextSubtreeNode = edge->val;
            edge = edge->next; // Move to next value
        }

        return nextSubtreeNode;
    }
    int total_node_count() const
    {
        return total_node_counter; // Counter of all nodes in the tree.
    }
    int edge_count() const
    {
        return (edge_counter / 2); // node_counter count for every connection made eg. subtree to edgenode
        // should be from subtree to subtree hence divide by 2.
    }
    int node_count() const
    {
        int node_counter = total_node_counter - (edge_counter / 2);
        return node_counter; // Total no. total nodes - edge nodes should give number of nodes in tree
    }

    int leaf_node_count() const
    {
        return count_leaf_nodes(t); // calls back to private function to count leaves.
    }

    TreeNode *get_t_pointer() // this was an extra function to get the pointer in order to print tree in main.
    {
        return t;
    }
};
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
int main()
{

    // direct initialisation of a vector
    // in this case it's a vector containing vectors
    // each of which contains words (std::string)
    std::vector<std::vector<std::string>> input{
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
        {"high", "no", "strong", "poor"}};

    A3Tree t(input);

    // direct initialisation of a vector:
    std::vector<std::string> q{"low", "yes", "strong"};

    std::cout << t.query(q) << std::endl;
    // this should print: poor

    // assigning new content overwriting the previous content:
    q = {"high", "yes", "moderate"};

    std::cout << t.query(q) << std::endl;
    // this should print: acceptable

    std::cout << t.total_node_count() << std::endl;
    std::cout << t.edge_count() << std::endl;

    std::cout << t.node_count() << std::endl;
    // From full tree with temperature root node no. = 16.

    std::cout << t.leaf_node_count() << std::endl;
    // From full tree with temperature root leaf no. = 10.

    print_tree(t.get_t_pointer());

    std::vector<std::vector<std::string>> input2{
        {"Feature_3", "feature2", "feature", "feature0", "not_a_feature"},
        {"a13480", "10", "a13480", "a", "1"},
        {"B_34203", "9", "1343432", "a", "a2"},
        {"a13480", "8", "57657", "a", "3"},
        {"B_34203", "B_34203", "4523", "a", "2"},
        {"B_34203", "6", "4523", "a", "some_value"},
        {"a13480", "5", "4523", "a", "1"}};

    A3Tree t2(input2);

    std::vector<std::string> p;

    p = {"B_34203", "9", "1343432", "a"};
    std::cout << t2.query(p) << std::endl;
    // this should print: a2

    std::cout << t2.node_count() << std::endl;
    // From full tree with temperature root node no. = 16.

    std::cout << t2.leaf_node_count() << std::endl;
}