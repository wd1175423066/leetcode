/*
 * @lc app=leetcode.cn id=450 lang=cpp
 *
 * [450] 删除二叉搜索树中的节点
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return root;
        if(root -> val == key) {
            // null null
            if(root -> left == nullptr && root -> right == nullptr) {
                delete root;
                return nullptr;
            }
            // null not null
            else if(root -> left == nullptr) return root -> right;
            else if(root -> right == nullptr) return root -> left;
            else {
                TreeNode* cur = root -> right;
                while(cur -> left) {
                    cur = cur -> left;
                }
                cur -> left = root -> left;
                //delete cur node
                TreeNode* tmp = root;
                root = root -> right;
                delete tmp;
                return root;
            }
        }

        else if(root -> val > key) root -> left = deleteNode(root -> left, key);
        else root -> right = deleteNode(root -> right, key);  
        return root;
    }
};
// @lc code=end

