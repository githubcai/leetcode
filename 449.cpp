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
    TreeNode* buildTree(const vector<int> &vec, int st, int ed){
        if(st > ed) return NULL;
        TreeNode *root = new TreeNode(vec[st]);
        if(st == ed) return root;
        int mid;
        for(mid = st + 1; mid <= ed; ++mid){
            if(vec[mid] > vec[st]) break;
        }
        root->left = buildTree(vec, st + 1, mid - 1);
        root->right = buildTree(vec, mid, ed);
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ret;
        if(root == NULL) return ret;
        stringstream ss;
        ss << root->val;
        ss >> ret;
        if(root->left != NULL) ret += "," + serialize(root->left);
        if(root->right != NULL) ret += "," + serialize(root->right);
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode *ret = NULL;
        if(data == "") return ret;
        vector<int> vec;
        for(int i = 0; i < data.size(); i += 1){
            string inp;
            while(i < data.size() && data[i] != ',') inp += string(1, data[i++]);
            stringstream ss;
            int temp;
            ss << inp;
            ss >> temp;
            vec.push_back(temp);
        }
        ret = buildTree(vec, 0, vec.size() - 1);
        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
