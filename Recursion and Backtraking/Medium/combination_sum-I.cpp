
// using recursive tree 
class Solution {
private:
    vector<vector<int>> ans;
    vector<int> combination;
    int sum;
public:
    void solve(int i,vector<int> candidates,int target){
       if(i==candidates.size()){
           if(target==0){
            ans.push_back(combination);
           }
           return;
       }
        if(target>=candidates[i]){
            combination.push_back(candidates[i]);
            solve(i,candidates,target-candidates[i]); //recursive call 
            combination.pop_back();
            
        }
        solve(i+1,candidates,target);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sum = 0;
        solve(0,candidates,target);
        return ans;
    }
};