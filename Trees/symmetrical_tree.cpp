class Solution {
public:
    bool issymmetric(TreeNode* node1,TreeNode* node2){
        if(node1==NULL || node2==NULL){
            return node1==node2;
        }
        if(node1->val!=node2->val){
            return false;
        }
        return (issymmetric(node1->left,node2->right)&&issymmetric(node1->right,node2->left));
    }
    bool isSymmetric(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        return issymmetric(root->left,root->right);
        
    }
};