class printPath{

public:
    bool printpathroot(Node* root,vector<int> &ans,int val){
        if(root==NULL){
            return false;
        }
        ans.push_back(root->val);
        if(root->val == val){
            return true;
        }
        if(printpathroot(root->left,ans,val)||printpathroot(root->right,ans,val)){
            return true;
        }
        ans.pop_back();
        return false;
    }
    int printpathfromroot(Node* root,int val){
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        printpathroot(root,ans,val);
        return ans;
    }

};