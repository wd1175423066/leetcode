/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
    bool isSymmetric(TreeNode* root) {
       return compare(root -> left, root -> right);
    }
    bool compare(TreeNode* p, TreeNode* q){
        if(!p && !q){
            return true;
        }
        else if(!p || !q){
            return false;
        }
        else if(p -> val != q -> val){
            return false;
        }
        else{
            return compare(p -> left, q->right) && compare(p -> right, q -> left);
        }
    }
};
// @lc code=end

