class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,vector<int>> mp;
        queue<pair<int,TreeNode*>> q;
        q.push(make_pair(0,root));
        while(!q.empty()){
            multiset<pair<int,int>> temp;
            int len = q.size();
            for(int i=0;i<len;++i){
                auto node = q.front();
                q.pop();
                temp.insert(make_pair(node.first,node.second->val));
                if(node.second->left){
                    q.push(make_pair(node.first-1,node.second->left));
                }
                if(node.second->right){
                    q.push(make_pair(node.first+1,node.second->right));
                }
            }
            for(auto p:temp){
                mp[p.first].push_back(p.second);
            }
        }
        vector<vector<int>> res;
        for(auto kv:mp){
            res.push_back(kv.second);
        }
        return res;
        
    }
};