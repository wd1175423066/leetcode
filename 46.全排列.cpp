/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path;
        vector<int> used(n);
        function<void()> backtracking = [&]{
            if(path.size() == n){
                ans.push_back(path);
                return;
            }
            for(int i = 0; i < n; ++i){
                if(used[i]) continue;
                path.push_back(nums[i]);
                used[i] = 1;
                backtracking();
                path.pop_back();
                used[i] = 0;
            }
        };
        backtracking();
        return ans;
    }

    // void backtracking(vector<vector<int>>& ans, vector<int>& path, vector<int>& used, vector<int>& nums, const int n){
    //     if(path.size() == n){
    //         ans.push_back(path);
    //     }
    //     for(int i = 0; i < n; ++i){
    //         if(used[i]) continue;
    //         path.push_back(nums[i]);
    //         used[i] = 1;
    //         backtracking(ans, path, used, nums, n);
    //         path.pop_back();
    //         used[i] = 0;
    //     }
    // }
};
// @lc code=end

