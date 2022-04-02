#include <bits/stdc++.h>
using namespace std;
void sort_k_sortedarray(vector<int> arr, int k, vector<int> &ans)
{
    priority_queue<int, vector<int>, greater<int>> minh;
    // for (int i = 0; i <k; ++i)
    // {
    //     minh.push(arr[i]);
    // }
    // for (int i = k; i < n; ++i)
    // {
    //     minh.push(arr[i]);
    //     ans.push_back(minh.top());
    //     minh.pop();
    // }
    // while (!minh.empty())
    // {
    //     ans.push_back(minh.top());
    //     minh.pop();
    // }
    for (int i = 0; i < arr.size(); ++i)
    {
        minh.push(arr[i]);
        if (minh.size() > k)
        {
            ans.push_back(minh.top());
            minh.pop();
        }
    }
    while (!minh.empty())
    {
        ans.push_back(minh.top());
        minh.pop();
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr;
    int x;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        arr.push_back(x);
    }
    vector<int> ans;
    sort_k_sortedarray(arr,3, ans);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}