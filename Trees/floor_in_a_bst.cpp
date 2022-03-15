int floorOfBST(Node* root){
    int floor = -1;
    while(root){
        if(root->val == val){
            floor = root->val;
        }else if(root->val >val){
            root = root->left;
        }else{
            floor= root->val;
            root = root->right;
        }
    }
}