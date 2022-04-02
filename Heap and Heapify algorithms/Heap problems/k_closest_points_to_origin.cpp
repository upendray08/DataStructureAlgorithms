class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> maxh;
        int n = points.size();
        for(int i=0;i<n;++i){
            int m = points[i].size();
            // int px =0;
            // int py =0;
            double dist= 0;
            for(int j=0;j<m;++j){
                dist+=pow(points[i][j]-0,2);
            }
            maxh.push({dist,{points[i][0],points[i][1]}});
            if(maxh.size()>k){
                maxh.pop();
            }
        }
        vector<vector<int>> ans;
        while(!maxh.empty()){
            vector<int> temp;
            for(int i=0;i<maxh.top().second.size();++i){
                temp.push_back()
            }
            maxh.pop();
            ans.push_back(temp);
            
        }
        return ans;
    }
};