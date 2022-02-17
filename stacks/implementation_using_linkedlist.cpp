// linkedlist implementation of stack
#include <iostream>
using namespace std;
struct stack
{
    int data;
    stack *link;
};
stack *top = NULL;
void push(int val)
{
    stack *temp = new stack();
    temp->data = val;
    temp->link = top;
    top = temp;
}
void pop()
{
    stack *temp;
    if (top == NULL)
    {
        cout << "empty stack" << endl;
    }
    temp = top;
    top = top->link;
    delete temp;
}
void tranverse()
{
    if (top == NULL)
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        cout << "Top of element of stack is: " << top->data << endl;
        if (top->link != NULL)
        {
            cout << "other: ";
            stack *current = top->link;
            while (current)
            {
                cout << current->data << " ";
                current = current->link;
            }
        }
        cout << endl;
    }
}
int main()
{
    stack st;
    for (int i = 0; i < 5; ++i)
    {
        push(i + 1);
    }
    tranverse();
    for(int i=0;i<5;++i){
        pop();
    }
    tranverse();
    return 0;
}