/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return nullptr;
        // find max value
        int max = nums[0];
        int max_index = 0;
        for(int i = 0; i < n; ++i) {
            if(nums[i] > max) {
                max = nums[i];
                max_index = i;
            }
        }
        // create node
        TreeNode* root = new TreeNode(max);
        if(n == 1) return root;
        //cut left and right array
        vector<int> leftNums(nums.begin(), nums.begin() + max_index);
        vector<int> rightNums(nums.begin() + max_index + 1, nums.end());
        //recursive
        root -> left = constructMaximumBinaryTree(leftNums);
        root -> right = constructMaximumBinaryTree(rightNums);
        return root;
    }
};
// @lc code=end

