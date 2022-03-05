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
void traversalOfTree(Node *node, vector<int> &pre, vector<int> &inorder, vector<int> &post)
{
    stack<pair<Node *, int>> st;
    if (node == NULL)
    {
        return;
    }
    st.push({node, 1});
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            inorder.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }
        else
        {
            post.push_back(it.first->data);
        }
    }
}
int main()
{
    Node *root = new Node(0);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->right->left = new Node(7);
    root->right->right = new Node(8);
    root->right->right->left = new Node(9);
    root->right->right->right = new Node(10);
    vector<int> pre;
    vector<int> inorder;
    vector<int> post;
    traversalOfTree(root, pre, inorder, post);
    if (root != NULL)
    {
        cout << "preorder traversal: ";
        for (auto i : pre)
        {
            cout << i << " ";
        }
        cout << endl;
        cout << "inorder traversal: ";
        for (auto i : inorder)
        {
            cout << i << " ";
        }
        cout << endl;
        cout << "postorder traversal: ";
        for (auto i : post)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "I cann't print traversal because root is not present " << endl;
    }
    return 0;
}