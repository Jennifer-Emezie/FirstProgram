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



void cons_tree() {
    int s;
    if ( s >= input.size() || input [s] == 0){
        return; 
    }
}