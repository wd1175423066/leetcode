/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
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
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        // int leftNum = countNodes(root -> left);
        // int rightNum = countNodes(root -> right);
        // return leftNum + rightNum + 1;
        //完全二叉树 只有最底层不满 且集中在左边
        TreeNode* left = root -> left;
        TreeNode* right = root -> right;
        int leftHeight = 0;
        int rightHeight = 0;
        while(left) {
            left = left -> left;
            ++leftHeight;
        }
        while(right) {
            right = right -> right;
            ++rightHeight;
        }
        if(leftHeight == rightHeight) {
            return (2 << leftHeight) - 1;
        }
        return countNodes(root -> left) + countNodes(root -> right) + 1;
    }
};
// @lc code=end

