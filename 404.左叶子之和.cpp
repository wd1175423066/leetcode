/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int leftValue = sumOfLeftLeaves(root -> left);
        int rightValue = sumOfLeftLeaves(root -> right);
        int midValue = 0;
        if(root -> left && !root -> left -> left && !root -> left -> right) {
            midValue = root -> left -> val;
        }
        int sum = midValue + leftValue + rightValue;
        return sum;
    }
};
// @lc code=end

