/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> comb;
        vector<vector<int>> ans;
        int sum = 0;
        int num = 0;
        int pos = 1;
        backtracking(ans, comb, k, n, sum, num, pos);
        return ans;
    }

    void backtracking(vector<vector<int>>& ans, vector<int>& comb, const int k, const int n, int& sum, int& num, int pos){
        if(num == k){
            if(sum == n){
                ans.push_back(comb);
            }
            return;
        }
        else{
            if(sum >= n){
                return;
            }
            else{
                for(int i = pos; i <= 9; ++i){
                    sum += i;
                    ++num;
                    comb.push_back(i);
                    backtracking(ans, comb, k, n, sum, num, i + 1);
                    comb.pop_back();
                    --num;
                    sum -= i;
                }
            }
        }
    }
};
// @lc code=end

