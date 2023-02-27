/*
 * @lc app=leetcode.cn id=501 lang=cpp
 *
 * [501] 二叉搜索树中的众数
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
    int maxCount = 0;
    int curCount = 0;
    TreeNode* pre = nullptr;
    vector<int> ans;
    void searchBST(TreeNode* cur) {
        if(!cur) return;
        searchBST(cur -> left);

        if(!pre) {
            curCount = 1;
        }
        else if(pre -> val == cur -> val) {
            ++curCount;
        }
        else{
            curCount = 1;
        }
        pre = cur;
        if(curCount == maxCount) {
            ans.push_back(cur -> val);
        }
        if(curCount > maxCount) {
            maxCount = curCount;
            ans.clear();
            ans.push_back(cur -> val);
        }

        searchBST(cur -> right);
    }

public:
    vector<int> findMode(TreeNode* root) {
        searchBST(root);
        return ans;
    }
};
// @lc code=end

