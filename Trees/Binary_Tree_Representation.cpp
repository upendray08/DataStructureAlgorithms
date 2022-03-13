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
void preorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}
void postorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}
void inorder(Node *node)
{
    if (node == NULL)
    {
        return;
    }
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}
bool printpathroot(Node *root, vector<int> &ans, int val)
{
    if (root == NULL)
    {
        return false;
    }
    ans.push_back(root->data);
    if (root->data == val)
    {
        return true;
    }
    if (printpathroot(root->left, ans, val) || printpathroot(root->right, ans, val))
    {
        return true;
    }
    ans.pop_back();
    return false;
}
// int printpathfromroot(Node *root, int val)
// {
//     vector<int> ans;
//     if (root == NULL)
//     {
//         return ans;
//     }
//     printpathroot(root, ans, val);
//     return ans;
// }
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    cout << "Pre-Order Tranversal:";
    preorder(root);
    cout << endl;
    cout << "In-Order Tranversal:";
    inorder(root);
    cout << endl;
    cout << "Post-Orders Tranversal:";
    postorder(root);
    cout << endl;

    // checking the print path from root question

    // int val = 9;
    // vector<int> ans;
    // printpathroot(root, ans, val);
    // cout << "this is path of node-9 form root: ";
    // for (auto i : ans)
    // {
    //     cout << i << " ";
    // }

    return 0;
}