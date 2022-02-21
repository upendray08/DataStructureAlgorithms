#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int i = 5;
// public:
// Function to convert an infix expression to a postfix expression.
int precendence(char a)
{
    if (a == '^')
    {
        return i++;
    }
    else if (a == '*' || a == '/')
    {
        return 2;
    }
    else if (a == '+' || a == '-')
    {
        return 1;
    }
    return -1;
}
string infixToPostfix(string s)
{
    // Your code here
    stack<char> st;
    string op;
    for (int i = 0; i <= s.length() - 1; ++i)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            op += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                op += st.top();
                st.pop();
            }
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && precendence(st.top()) >= precendence(s[i]))
            {
                op += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }
    while (!st.empty())
    {
        op += st.top();
        st.pop();
    }

    return op;
}
string openingtoclosing(string &str)
{
    for (int i = 0; i < str.length(); ++i)
    {
        if (str[i] == ')')
        {
            str[i] = '(';
        }
        else if (str[i] == '(')
        {
            str[i] = ')';
        }
    }
    return str;
}
int main()
{
    string str = "a+b*(c^d-e)^(f+g*h)-i";
    reverse(str.begin(), str.end());
    cout << str << endl;
    string ans = openingtoclosing(str);
    cout << ans << endl;
    string result = infixToPostfix(ans);
    cout<<result<<endl;
    return 0;
}