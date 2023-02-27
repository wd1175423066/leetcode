/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preOrderSize = preorder.size();
        if(preOrderSize == 0) return nullptr;
        int rootValue = preorder[0];
        TreeNode* root = new TreeNode(rootValue);
        if(preOrderSize == 1) return root;

        int index;
        for(index = 0; index < inorder.size(); ++index) {
            if(inorder[index] == rootValue) break;
        }
        
        vector<int> leftInOrder(inorder.begin(), inorder.begin() + index);
        vector<int> rightInOrder(inorder.begin() + index + 1, inorder.end());

        preorder.erase(preorder.begin());
        vector<int> leftPreOrder(preorder.begin(), preorder.begin() + index);
        vector<int> rightPreOrder(preorder.begin() + index, preorder.end());

        root -> left = buildTree(leftPreOrder, leftInOrder);
        root -> right = buildTree(rightPreOrder, rightInOrder);

        return root;
    }
};
// @lc code=end

