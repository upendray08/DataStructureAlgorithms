#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int evaluatePrefix(string &exp)
{
    stack<int> st;
    int size = exp.length();
    for (int i = size - 1; i >= 0; --i)
    {
        if (exp[i] >= '0' && exp[i] <= '9')
        {
            st.push(exp[i]-'0');
        }
        else
        {
            int o1 = st.top();
            st.pop();
            int o2 = st.top();
            st.pop();
            switch (exp[i])
            {
            case '+':
                st.push(o1 + o2);
                break;
            case '-':
                st.push(o1 - o2);
                break;
            case '^':
                st.push(pow(o1, o2));
                break;
            case '*':
                st.push(o1 * o2);
                break;
            case '/':
                st.push(o1 / o2);
                break;
            }
        }
    }
    return st.top();
}
int main()
{
    string exprsn = "+9*26";
    cout << evaluatePrefix(exprsn) << endl;
    // cout << evaluatePrefix(exprsn) << endl;
    return 0;
}