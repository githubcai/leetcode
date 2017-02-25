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
    TreeNode* dfs(const string &data, int &ind){
        TreeNode *root = NULL;
        if(ind == data.size()) return root;
        int temp = ind;
        while(ind < data.size() && data[ind] != ',') ind += 1;
        string str = data.substr(temp, ind - temp);
        ind += 1;
        if(str != "#"){
            stringstream ss;
            ss << str;
            int temp;
            ss >> temp;
            root = new TreeNode(temp);
            root->left = dfs(data, ind);
            root->right = dfs(data, ind);
        }
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        if(root == NULL) return ret + "#";
        stringstream ss;
        ss << root->val;
        ss >> ret;
        if(root->left != NULL){
            ret += "," + serialize(root->left);
        }else{
            ret += ",#";
        }
        if(root->right != NULL){
            ret += "," + serialize(root->right);
        }else{
            ret += ",#";
        }
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int ind = 0;
        return dfs(data, ind);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
