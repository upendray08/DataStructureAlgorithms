class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        vector<int> ans;
        map<int,int> mp;
        queue<pair<Node*,int>> q;
        if(root==NULL){
            return ans;
        }
        q.push({root,0});
        while(!q.empty()){
            auto temp=q.front();q.pop();
            if(mp.find(temp.second)==mp.end()){
                mp[temp.second]=temp.first->data;
            }
            if(temp.first->left){
                q.push({temp.first->left,temp.second-1});
            }
            if(temp.first->right){
                q.push({temp.first->right,temp.second+1});
            }
        }
        for(auto p:mp){
            ans.push_back(p.second);
        }
        return ans;
    }

};