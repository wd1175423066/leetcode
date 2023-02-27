/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 */

// @lc code=start
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
       ostringsteam out;
       serialize(root, out);
       return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        instringsteam in(data);
        return deserialize(in);
    }
private:
    void serialize(TreeNode* root, ostringsteam& out){
        if(!root){
            out << "# ";
            return;
        }
        out << root -> val << " ";
        serialize(root -> left, out);
        serialize(root -> right, out);
    }
    TreeNode* deserialize(instringsteam& in){
        string val;
        in >> val;
        if(val == "#"){
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(val));
        root -> left = deserialize(in);
        root -> right = deserialize(in);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

