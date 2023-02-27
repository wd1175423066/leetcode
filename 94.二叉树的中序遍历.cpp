/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> result;
        vector<int> left = inorderTraversal(root -> left);
        vector<int> right = inorderTraversal(root -> right);
        result.insert(result.end(), left.begin(), left.end());
        result.push_back(root -> val);
        result.insert(result.end(), right.begin(), right.end());
        return result;
    }
};
// @lc code=end

