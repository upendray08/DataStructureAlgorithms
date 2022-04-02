class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // vector<int> absolute;
        priority_queue<pair<int,int>> maxh;
        // for(int i=0;i<arr.size();++i){
        //     absolute.push_back(abs(arr[i]-x));
        // }
        for(int i=0;i<arr.size();++i){
            maxh.push({abs(arr[i]-x),arr[i]});
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        vector<int> ans;
        while(!maxh.empty()){
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};