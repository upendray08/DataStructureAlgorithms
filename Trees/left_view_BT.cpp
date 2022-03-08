vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> ans;
   queue<pair<Node*,int>> q;
   map<int,int> mp;
   q.push({root,0});
   if(root==NULL){
       return ans;
   }
   while(!q.empty()){
       auto t = q.front();q.pop();
       if(mp.find(t.second)==mp.end()){
           mp[t.second] = t.first->data;
       }
       if(t.first->left){
           q.push({t.first->left,t.second+1});
       }
       if(t.first->right){
           q.push({t.first->right,t.second+1});
       }
   }
   for(auto i:mp){
       ans.push_back(i.second);
   }
   return ans;
}