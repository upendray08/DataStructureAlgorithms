#include <iostream>
using namespace std;
class stack
{
private:
    int *array;
    int size;
    int tos;

public:
    stack()
    {
        size = 10;
        array = new int[size];
        tos = -1;
    }
    stack(int size)
    {
        this->size = size;
        array = new int[size];
        tos = -1;
    }
    void push(int value);
    int pop();
    void tranverse();
};
void stack::push(int value)
{
    if (tos == size - 1)
    {
        cout << "stack is full" << endl;
    }
    else
    {
        array[++tos] = value;
    }
}
int stack::pop()
{
    if (tos == -1)
    {
        return -1;
    }
    else
    {
        return array[tos--];
    }
}
void stack::tranverse()
{
    int temp = tos;
    if (tos == -1)
    {
        cout << "stack is empty" << endl;
    }
    else
    {
        // cout << "top element is: " << array[tos] << endl;
        // if (temp > -1)
        // {
        //     cout << "Other: ";
        // }
        cout<<"elements of stack is: "<<endl;
        while (temp > -1)
        {
            cout << array[temp] << " ";
            temp--;
        }

        cout << endl;
    }
}
int main()
{
    stack st(5);
    st.push(1);
    st.push(5);
    st.push(10);
    st.push(20);
    st.push(30);
    st.tranverse();
    cout<<st.pop()<<endl;
    cout<<"after the pop has done "<<endl;
    st.tranverse();
    return 0;
}