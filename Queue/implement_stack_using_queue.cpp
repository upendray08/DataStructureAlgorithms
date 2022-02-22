#include <iostream>
#include <queue>
using namespace std;
class QueueStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int);
    int pop();
    void printQueuestack();
};

// Function to push an element into stack using two queues.
void QueueStack ::push(int x)
{
    // Your Code
    q1.push(x);
}

// Function to pop an element from stack using two queues.
int QueueStack ::pop()
{
    // Your Code
    if (q1.empty())
    {
        return -1;
    }
    while (q1.size() != 1)
    {
        q2.push(q1.front());
        q1.pop();
    }
    int ans = q1.front();
    q1.pop();
    while (!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }
    return ans;
}
int main()
{
    QueueStack q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    int val = q.pop();
    return 0;
}