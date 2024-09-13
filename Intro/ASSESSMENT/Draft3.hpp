#include <iostream>
#include <string>
#include <vector>

struct TreeNode;
struct EdgeNode;

typedef std::string tree_t;

struct EdgeNode {
    tree_t val;
    TreeNode* subtree;
    EdgeNode* next;
};

struct TreeNode {
    tree_t val;
    EdgeNode* subtree_l;
};

class A3Tree {
private:
    TreeNode* root;
    int nodeCount;

public:
    A3Tree(std::vector<std::vector<std::string>> input) {
        root = nullptr;
        nodeCount = 0;

        if (!input.empty()) {
            root = new TreeNode();
            root->val = input[0][0];
            nodeCount++;

            buildTree(root, input, 1, root->subtree_l);
        }
    }

    void buildTree(TreeNode* parent, const std::vector<std::vector<std::string>>& input, int level, EdgeNode*& edge) {
        if (level >= input.size() || input[level].empty()) {
            return;
        }

        for (const auto& value : input[level]) {
            EdgeNode* newEdge = new EdgeNode();
            newEdge->val = value;
            newEdge->subtree = new TreeNode();
            newEdge->subtree->val = value;
            newEdge->next = nullptr;

            if (edge == nullptr) {
                parent->subtree_l = newEdge;
                edge = parent->subtree_l;
            } else {
                edge->next = newEdge;
                edge = edge->next;
            }

            nodeCount++;

            buildTree(newEdge->subtree, input, level + 1, newEdge->subtree->subtree_l);
        }
    }

    std::string query(const std::vector<std::string>& input) {
        // Placeholder function for querying the tree
        return "";  // Return the result of the query
    }

    int node_count() const {
        return nodeCount;
    }

    int leaf_node_count() const {
        // Placeholder function for counting leaf nodes
        return 0;  // Return the number of leaf nodes
    }
};

void buildTree(TreeNode* parent, const std::vector<std::vector<std::string>>& input, int level, std::map<std::string, TreeNode*>& nodeMap) {
    if (level >= input.size() || input[level].empty()) {
        return;
    }

    for (const auto& value : input[level]) {
        EdgeNode* newEdge = new EdgeNode();
        newEdge->val = value;

        // Check if the node with the current value already exists in the map
        if (nodeMap.find(value) != nodeMap.end()) {
            newEdge->subtree = nodeMap[value];  // Reuse the existing node
        } else {
            newEdge->subtree = new TreeNode();
            newEdge->subtree->val = value;
            nodeMap[value] = newEdge->subtree;  // Add the new node to the map
        }

        newEdge->next = nullptr;

        if (parent->subtree_l == nullptr) {
            parent->subtree_l = newEdge;
        } else {
            EdgeNode* edge = parent->subtree_l;
            while (edge->next != nullptr) {
                edge = edge->next;
            }
            edge->next = newEdge;
        }

        buildTree(newEdge->subtree, input, level + 1, nodeMap);
    }
}


int main() {
    std::vector<std::vector<std::string>> input = {
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

    std::vector<std::string> q{"low", "yes", "strong"};
    std::cout << t.query(q) << std::endl;

    q = {"high", "yes", "moderate"};
    std::cout << t.query(q) << std::endl;

    std::cout << t.node_count() << std::endl;
    std::cout << t.leaf_node_count() << std::endl;

    return 0;
}
