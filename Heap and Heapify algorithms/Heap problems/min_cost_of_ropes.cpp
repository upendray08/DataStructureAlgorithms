class Solution
{
    public:
    //Function to return the minimum cost of connecting the ropes.
    long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long >,greater<long long>> minh;
        for(int i=0;i<n;++i){
            minh.push(arr[i]);
        }
        if(n<=1){
            return 0;
        }
        long long ans = 0;
        while(minh.size()>=2){
            long long first = minh.top();minh.pop();
            long long second = minh.top();minh.pop();
            ans +=(first+second);
            minh.push(first+second);
        }
        
        return ans;
        
    }
};