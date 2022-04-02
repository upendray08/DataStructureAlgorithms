class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();++i){
            mp[nums[i]]++;
        }
        priority_queue<pair<int,int>> minh;
        for(auto i:mp){
            //-minus is helping for same frequency to dec order elem
            minh.push({-i.second,i.first});
        }
        vector<int> ans;
        while(!minh.empty()){
            int count = abs(minh.top().first);
            int ele = minh.top().second;
            
            while(count--){
                ans.push_back(ele);
            }
            minh.pop();
        }
        return ans;
    }
};