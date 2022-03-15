int ceilusingBST(){
    Node* ceil;
    while(root){
        if(root->val == val){
            ceil= root;
            return ceil;
        }else if(root->val > val){
            ceil = root;
            root = root->left;
        }else{
            root = root->right;
        }
    }
}