/* A binary tree node has data, pointer to left child
   and a pointer to right child  

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

//Function to return a list containing the preorder traversal of the tree.
vector <int> preorder(Node* root)
{
  // Your code here
  vector<int> ans;
  stack<Node*> s;
  if(root==NULL){
      return ans;
  }
  s.push(root);
  while(!s.empty()){
    int n = s.size();
    for(int i=0;i<n;++i){
        Node* temp = s.top();
        s.pop();
        if(temp->right!=NULL){
            s.push(temp->right);
        }if(temp->left!=NULL){
            s.push(temp->left);
        }
        ans.push_back(temp->data);
    }
  }
  return ans;
}