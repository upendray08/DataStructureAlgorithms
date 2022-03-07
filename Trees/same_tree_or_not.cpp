#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
void preorder(Node *node, vector<int> &ans)
{
    if (node == NULL)
    {
        return;
    }
    ans.push_back(node->data);
    preorder(node->left, ans);
    preorder(node->right, ans);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(5);
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->right->left = new Node(4);
    root1->right->right = new Node(5);
    vector<int> res1, res2;
    preorder(root, res1);
    preorder(root1, res2);
    int n = res1.size();
    int m = res2.size();
    if (n != m)
    {
        cout << "false" << endl;
    }
    else
    {
        cout << "true" << endl;
    }
    return 0;
}