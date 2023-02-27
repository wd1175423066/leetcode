/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> comb;
        int sum = 0;
        int pos = 0;
        backtracking(candidates, target, ans, comb, sum, n, pos);
        return ans;
    }

    void backtracking(const vector<int> candidates, const int target, vector<vector<int>>& ans, vector<int>& comb, int& sum, const int n, int pos){
        if(sum == target){
            ans.push_back(comb);
            return;
        }
        else if(sum > target || pos == n){
            return;
        }
        else{
            for(int i = pos; i < n; ++i){
                sum += candidates[i];
                comb.push_back(candidates[i]);
                backtracking(candidates, target, ans, comb, sum, n, i);
                comb.pop_back();
                sum -= candidates[i];
            }
        }
    }
};
// @lc code=end

