/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
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
    bool isValidBST(TreeNode* root) {
        // if(!root) return true;
        // TreeNode* left = root -> left;
        // TreeNode* right = root -> right;
        // if(left && right){
        //     if(left -> val < root -> val && right -> val > root -> val){
        //         return isValidBST(left) && isValidBST(right);
        //     }
        //     else{
        //         return false;
        //     }
        // }
        // else if(left){
        //     if(left -> val < root -> val){
        //         return isValidBST(left);
        //     }
        //     else{
        //         return false;
        //     }
        // }
        // else if(right){
        //     if(right -> val > root -> val){
        //         return isValidBST(right);
        //     }
        //     else{
        //         return false;
        //     }
        // }
        // else{
        //     return true;
        // }
        return dfs(root, LONG_MIN, LONG_MAX);
    }
    
    bool dfs(TreeNode* root, long lower, long upper){
        if(!root) return true;
        if(lower >= root->val || upper <= root->val) return false;
        else return dfs(root->left, lower, root->val) && dfs(root->right, root->val, upper);
    }

};
// @lc code=end

