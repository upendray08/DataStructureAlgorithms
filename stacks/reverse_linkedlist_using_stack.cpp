#include <iostream>
#include <stack>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
// Node *head = NULL;
Node* insertAtBegining(Node *head, int val)
{
    Node *temp = new Node();
    temp->data = val;
    temp->next = head;
    head = temp;
    return head;
}

void printLinkedList(Node *head)
{
    Node *temp = head;
    cout << "Linkedlist elements are: ";
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void pushLinkedlistToStack(Node *head, stack<Node *> &S)
{
    Node *temp = head;
    while (temp)
    {
        S.push(temp);
        temp = temp->next;
    }
}
Node* stackToLinkedList(Node *head, stack<Node *> &S)
{
    Node *temp = S.top();
    head = temp;
    S.pop();
    while (!S.empty())
    {
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}
int main()
{
    stack<Node *> S;
    Node *head = NULL;
    head = insertAtBegining(head, 1);
    head = insertAtBegining(head, 2);
    head = insertAtBegining(head, 3);
    head = insertAtBegining(head, 4);
    head = insertAtBegining(head, 5);
    cout<<"before reversing linkedlist: "<<endl;
    printLinkedList(head);
    pushLinkedlistToStack(head, S);
    // int size = S.size();
    // cout<<size<<endl;
    // cout<<"stack element is: ";
    // for(int i=0;i<size;++i){
    //     cout<<(S.top())->data<<" ";
    //     S.pop();
    // }
    // cout<<endl;
    head = stackToLinkedList(head, S);
    cout<<"after reversing Linkedlist is: "<<endl;
    printLinkedList(head);
    // cout << endl;

    return 0;
}