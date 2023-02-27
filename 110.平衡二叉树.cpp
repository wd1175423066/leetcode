/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int left = calDepth(root -> left);
        int right = calDepth(root -> right);
        if(isBalanced(root -> left) && isBalanced(root -> right) && abs(left - right) <= 1) {
            return true;
        }
        else {
            return false;
        }
    }
    int calDepth(TreeNode* root) {
        if(!root) {
            return 0;
        }
        return max(calDepth(root -> left), calDepth(root -> right)) + 1;
    }
};
// @lc code=end

