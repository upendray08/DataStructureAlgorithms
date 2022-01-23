class Solution {
public:
    void solve(vector<int>&nums,int index,vector<vector<int>> &ans){
        int n= nums.size();
        if(index==n){
            ans.push_back(nums);
            return;
        }
        for(int i=index;i<n;++i){
            swap(nums[index],nums[i]);
            solve(nums,index+1,ans);
            swap(nums[index],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        solve(nums,0,ans);
        map<vector<int>,int> mp;
        for(int i=0;i<ans.size();++i){
            mp[ans[i]]++;
        }
        vector<vector<int>> res;
        for(auto i=mp.begin();i!=mp.end();++i){
            res.push_back(i->first);
        }
        return res;
    }
};