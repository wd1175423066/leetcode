/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> subset;
        int index = 0;
        backtracking(nums, ans, subset, index, n);
        return ans;
    }

    void backtracking(const vector<int>& nums, vector<vector<int>>& ans, vector<int>& subset, int index, const int n){
        ans.push_back(subset);
        if(index == n){
            return;
        }
        for(int i = index; i < n; ++i){
            subset.push_back(nums[i]);
            backtracking(nums, ans, subset, i + 1, n);
            subset.pop_back();
        }
    }
};
// @lc code=end

