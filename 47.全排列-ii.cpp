/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(begin(nums), end(nums));
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path;
        vector<int> used(n);
        function<void()> dfs = [&](){
            if(path.size() == n){
                ans.push_back(path);
                return;
            }
            for(int i = 0; i < n; ++i){
                if(used[i]) continue;
                // when nums[i-1] == nums[i] and !used[i-1],nums[i] should not be used
                if(i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
                path.push_back(nums[i]);
                used[i] = 1;
                dfs();
                path.pop_back();
                used[i] = 0;
            }
        };
        dfs();
        return ans;
    }
};
// @lc code=end

