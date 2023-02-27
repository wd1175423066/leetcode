/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int postOrderSize = postorder.size();
        if(postOrderSize == 0) return nullptr;
        // get postorder last ele
        int rootValue = postorder[postOrderSize - 1];
        TreeNode* root = new TreeNode(rootValue);

        if(postOrderSize == 1) return root;
        // find this ele in inorder
        int index;
        for(index = 0; index < inorder.size(); ++index) {
            if(inorder[index] == rootValue) break;
        }

        // cut two arrays
        // inorder
        vector<int> leftInOrder(inorder.begin(), inorder.begin() + index);
        vector<int> rightInOrder(inorder.begin() + index + 1, inorder.end());
        // postorder
        postorder.resize(postorder.size() - 1);
        vector<int> leftPostOrder(postorder.begin(), postorder.begin() + index);
        vector<int> rightPostOrder(postorder.begin() + index, postorder.end());

        // recursive
        root -> left = buildTree(leftInOrder, leftPostOrder);
        root -> right = buildTree(rightInOrder, rightPostOrder);
        
        return root;
    }
};
// @lc code=end

