/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL){
            return "";
        }
        string s = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* currNode = q.front();
            q.pop();
            if(currNode ==NULL){
                s.append("#,");
            }else{
                s.append(to_string(currNode->val)+',');
            }
            if(currNode!=NULL){
                q.push(currNode->left);
                q.push(currNode->right);
            }
        }
        cout<<s<<endl;
        return s;
        
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0){
            return NULL;
        }
        string str;
        stringstream a(data);
        getline(a,str,',');
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();q.pop();
            //left node
            getline(a,str,',');
            if(str=="#"){
                node->left = NULL;
            }else{
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left  = leftNode;
                q.push(leftNode);
            }
            //rightNode
            getline(a,str,',');
            if(str=="#"){
                node->right = NULL;
            }else{
                TreeNode* rightNode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));