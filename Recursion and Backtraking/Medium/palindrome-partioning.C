class Solution {
public:
    void solve(string s,int index,vector<string> path,vector<vector<string>> &ans){
        int n=s.length();
        if(index==n){
            ans.push_back(path);
            return;
        }
        for(int i=index;i<n;++i){
            if(ispalindrome(s,index,i)){
                path.push_back(s.substr(index,i-index+1));
                solve(s,i+1,path,ans);
                path.pop_back();
            }
        }
    }
    bool ispalindrome(string s,int l,int h){
        while(l<h){
            if(s[l++]!=s[h--]){
                return false;
            }
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        solve(s,0,path,ans);
        return ans;
    }
};