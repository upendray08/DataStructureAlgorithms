#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_set<int> s;
    int n = 5;
    for (int i = 0; i < n; ++i)
    {
        s.insert(i + 2);
    }
    // if element is present or not
    if (s.find(1) != s.end())
    {
        cout << "element is present" << endl;
    }
    else
    {
        cout << "element is not present" << endl;
    }
    // transverse
    for (auto i = s.begin(); i != s.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
    // count is also usesful
    if (s.count(4) != 0)
    {
        cout << "present " << endl;
    }
    else
    {
        cout << "not present" << endl;
    }
    // erase
    s.erase(3);
    // tranverse1
    for (auto i = s.begin(); i != s.end(); ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
    int count1 = s.count(5);
    cout << count1 << endl;
    auto i = s.find(2);
    auto j = s.find(5);
    while (i != j)
    {
        cout << *i << " ";
        i++;
    }
    return 0;
}