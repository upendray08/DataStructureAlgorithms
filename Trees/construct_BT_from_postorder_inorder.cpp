/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

//Function to return a tree created from postorder and inoreder traversals.
Node* createTree(int in[],int post[],int n,int start,int end ,int&postInd){
    if(start>end){
        return NULL;
    }
    Node* node = new Node(post[postInd--]);
    int pos;
    for(int i=start;i<=end;++i){
        if(in[i]==node->data){
            pos=i;
            break;
        }
    }
    node->right = createTree(in,post,n,pos+1,end,postInd);
    node->left = createTree(in,post,n,start,pos-1,postInd);
    return node;
}
Node *buildTree(int in[], int post[], int n) {
    // Your code here
    int postInd = n-1;
    return createTree(in,post,n,0,n-1,postInd);
}