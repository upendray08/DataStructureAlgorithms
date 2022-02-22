#include <iostream>
#include <stack>
using namespace std;
class myqueue
{
    stack<int> s1;
    stack<int> s2;

public:
    void push(int val);
    int pop();
    int peek();
    void printQueue();
};
void myqueue::push(int val)
{
    s1.push(val);
    return;
}
int myqueue::pop()
{
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    int ans = s2.top();
    while (!s2.empty())
    {
        s1.push(s2.top());
        s2.pop();
    }
    return ans;
}
int myqueue::peek()
{
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    return s2.top();
}
void myqueue::printQueue()
{
    while (!s1.empty())
    {
        s2.push(s1.top());
        s1.pop();
    }
    while (!s2.empty())
    {
        cout << s2.top() << " ";
        s2.pop();
    }
}
int main()
{
    myqueue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.printQueue();
    int pop1 = q.pop();
    cout<<pop1<<endl;
    return 0;
}