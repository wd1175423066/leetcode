/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int leftLen = minDepth(root -> left);
        int rightLen = minDepth(root -> right);
        if(root -> left && root -> right) {
            return min(leftLen, rightLen) + 1;
        }
        else if(root -> left) {
            return leftLen + 1;
        }
        else if(root -> right) {
            return rightLen + 1;
        }
        else{
            return 1;
        }
    }
};
// @lc code=end

