//using recursive tree 
class Solution {
private:
    vector<vector<int>> ans;
public:
    
    void solve(vector<int> ip,vector<int> op){
        if(ip.size()==0){
            ans.push_back(op);
            return;
        }
        vector<int> op1 = op;
        vector<int> op2 = op;
        op2.push_back(ip[0]);
        ip.erase(ip.begin()+0);
        solve(ip,op1);
        solve(ip,op2);
        return;
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> op;
        // vector<vector<int>> ans;
        solve(nums,op);
        map<vector<int> ,int> mp;
        for(int i=0;i<ans.size();++i){
            mp[ans[i]]++;
        }
        vector<vector<int>> res;
        for(auto i= mp.begin();i!=mp.end();++i){
            res.push_back(i->first);
        }
       return res; 
    }
};