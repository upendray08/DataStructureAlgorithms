class Solution
{
public:
    void solve(vector<int> ip,int sum ,vector<int> &ans){
        if(ip.size()==0){
            ans.push_back(sum);
            return;
        }
        int sum1 = sum;
        int sum2 = sum;
        sum2+= ip[0];
        ip.erase(ip.begin()+0);
        solve(ip,sum1,ans);
        solve(ip,sum2,ans);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ans ;
        int sum = 0;
        solve(arr,sum,ans);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};