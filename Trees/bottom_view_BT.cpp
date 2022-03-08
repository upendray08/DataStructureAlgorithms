class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        queue<pair<Node*,int>> q;
        map<int,int> mp;
        if(root==NULL){
            return {};
        }
        q.push({root,0});
        while(!q.empty()){
            auto t = q.front();q.pop();
            // if(mp.find(t.second)!=mp.end()){
            //     mp[t.second] = t.first->data;
            // }else{
            //     mp[t.second] = t.first->data;
            //     }//map value update
            
            mp[t.second] = t.first->data; // second way of updating map
            if(t.first->left){
                q.push({t.first->left,t.second-1});
            }
            if(t.first->right){
                q.push({t.first->right,t.second+1});
            }
        }
        vector<int> ans;
        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
        
    }
};