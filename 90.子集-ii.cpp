/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> comb;
        int index = 0;
        vector<bool> isPrev(n, false);
        sort(nums.begin(), nums.end());
        backtracking(nums, n, ans, comb, isPrev, index);
        return ans;
    }

    void backtracking(vector<int>& nums, const int n, vector<vector<int>>& ans, vector<int>& comb, vector<bool>& isPrev, int index){
        ans.push_back(comb);
        for(int i = index; i < n; ++i){
            if(i >=1 && nums[i] == nums[i - 1] && (!isPrev[i - 1])){
                continue;
            }
            comb.push_back(nums[i]);
            isPrev[i] = true;
            backtracking(nums, n, ans, comb, isPrev, i + 1);
            comb.pop_back();
            isPrev[i] = false;
        }
    }
};
// @lc code=end

