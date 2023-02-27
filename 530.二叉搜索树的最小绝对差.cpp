/*
 * @lc app=leetcode.cn id=530 lang=cpp
 *
 * [530] 二叉搜索树的最小绝对差
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
private:
    int result = INT_MAX;
    TreeNode* pre;
    void traversal(TreeNode* cur) {
        if(!cur) return;
        traversal(cur -> left);
        if(pre) {
            result = min(result, abs(pre -> val - cur -> val));
        }
        pre = cur;
        traversal(cur -> right);

    }

public:
    int getMinimumDifference(TreeNode* root) {
        traversal(root);
        return result;
    }
};
// @lc code=end

