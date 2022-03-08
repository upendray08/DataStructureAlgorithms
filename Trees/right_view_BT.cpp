class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> ans;
        queue<pair<Node*,int>> q;
        map<int,int> mpp;
        q.push({root,0});
        if(root==NULL){
            return ans;
        }
        while(!q.empty()){
            auto t=q.front();q.pop();
            mpp[t.second] = t.first->data;
            if(t.first->left){
                q.push({t.first->left,t.second+1});
            }
            if(t.first->right){
                q.push({t.first->right,t.second+1});
            }
        }
        for(auto i:mpp){
            ans.push_back(i.second);
        }
        return ans;
    }
};