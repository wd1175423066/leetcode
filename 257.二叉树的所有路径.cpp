/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        vector<int> path;
        binaryTreePaths(root, ans, path);
        return ans;
    }

    void binaryTreePaths(TreeNode* root, vector<string>& ans, vector<int>& path) {
        path.push_back(root -> val);
        if(root -> left == nullptr && root -> right == nullptr) {
            ans.push_back(pathToS(path));
            return;
        }
        if(root -> left) {
            binaryTreePaths(root -> left, ans, path);
            path.pop_back();
        }
        if(root -> right) {
            binaryTreePaths(root -> right, ans, path);
            path.pop_back();
        }

    }

    string pathToS(vector<int>& path) {
        string res;
        for(int i = 0; i < path.size() - 1; ++i) {
            res += to_string(path[i]) + "->";
        }
        res += to_string(path[path.size() - 1]);
        return res;
    }
};
// @lc code=end

