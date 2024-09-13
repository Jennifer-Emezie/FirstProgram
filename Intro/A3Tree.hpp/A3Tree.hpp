 t = NULL;
    node_counter = 0;

if (input.size() != 0 ){
    t = new TreeNode(); 
    t -> val = input[0][0]; //use first element for root node
    node_counter ++; // since a node has been added add to node count
}


    TreeNode* currentNode = t; // This will be the root node

    //Starting with the rows of vector table (chosing the string)
    //Then then counting through the vector chosen. 
    for (int i = 1; i <input.size(); i++){ // starts at 1 since first element was already put in.
        for (int j=0; j< input[i].size(); j++){
            const std::string& value = input [i][j];
            TreeNode* findNode = NULL; 

// Here we are checking to see if the node already exisits. 
//If it does then ass edeg val to it.
        EdgeNode* edge = currentNode->subtree_l;
        while (edge != NULL) {
            if (edge->val == value){
                findNode = edge->subtree;
                return;
            }
            edge = edge->next;
        } 
// If not then create node. 
        if (findNode == NULL){ 
TreeNode* newNode = allocate_tree_node(value);
                currentNode->subtree_l = cons_edge_node(newNode, currentNode->subtree_l);
                node_counter++;
                currentNode = newNode;
        }
        else {
            // Here we are using the existing node.
            currentNode= findNode;

        }


        }

    }