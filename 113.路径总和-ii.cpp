/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> cur;
        pathSum(root, targetSum, ans, cur);
        return ans;
    }

    void pathSum(TreeNode* root, int targetSum, vector<vector<int>>& ans, vector<int>& cur) {
        if(!root) return;
        if(!root -> left && !root -> right && root -> val == targetSum) {
            cur.push_back(root -> val);
            ans.push_back(cur);
            cur.pop_back();
            return;
        }
        if(root -> left) {
            cur.push_back(root -> val);
            pathSum(root -> left, targetSum - root -> val, ans, cur);
            cur.pop_back();
        }
        if(root -> right) {
            cur.push_back(root -> val);
            pathSum(root -> right, targetSum - root -> val, ans, cur);
            cur.pop_back();
        }

    }
};
// @lc code=end

