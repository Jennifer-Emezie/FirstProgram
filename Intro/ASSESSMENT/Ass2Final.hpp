#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

struct TreeNode;
struct EdgeNode;

typedef std::string tree_t;

struct EdgeNode
{
    TreeNode *subtree;
    EdgeNode *next;
};

struct TreeNode
{
    tree_t val;
    EdgeNode *subtree_l;
};

TreeNode *allocate_tree_node(tree_t e)
{
    TreeNode *tmp = new TreeNode;
    tmp->val = e;
    tmp->subtree_l = NULL;
    return tmp;
}

EdgeNode *cons_edge_node(TreeNode *t, EdgeNode *subtree_l)
{
    EdgeNode *tmp = new EdgeNode;
    tmp->subtree = t;
    tmp->next = subtree_l;
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

        TreeNode *child = allocate_tree_node(d);

        parent->subtree_l = cons_edge_node(child, parent->subtree_l);
    }
}

int count_nodes(TreeNode *t)
{

    if (t == NULL)
    {
        return 0;
    }
    int c = 0;
    for (EdgeNode *it = t->subtree_l; it != NULL; it = it->next)
    {

        c = count_nodes(it->subtree) + c;
    }
    return 1 + c;
}

int count_leaf_nodes(TreeNode *t)
{

    if (t == NULL)
    {
        return 0;
    }

    int c = 0;

    for (EdgeNode *it = t->subtree_l; it != NULL; it = it->next)
    {

        c = count_leaf_nodes(it->subtree) + c;
    }

    return (t->subtree_l == NULL) + c;
}

void deallocate_tree(TreeNode *t)
{
    if (t == NULL)
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

int main()
{

    std::string filename;
    std::cin >> filename;

    std::ifstream infile;
    infile.open(filename);

    if (!infile.is_open())
    {
        std::cout << "error opening file" << std::endl;
        return (EXIT_FAILURE);
    }

    std::string s1, s2;
    infile >> s1;

    TreeNode *t1;
    t1 = build_tree_root(s1);

    while (infile >> s1 >> s2)
    {
        add_tree_node(s1, s2, t1);
    }

    print_tree(t1);

    std::cout << "node count: " << count_nodes(t1) << std::endl;
    std::cout << "leaf node count: " << count_leaf_nodes(t1) << std::endl;

    deallocate_tree(t1);
}