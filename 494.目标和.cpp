/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        long sum = 0;
        for(const int num : nums) sum += num;
        if((sum + target) % 2 == 1) return 0;
        if(abs(target) > sum) return 0;

        int bag_size = (sum + target) / 2;
        vector<int> dp(bag_size + 1, 0);
        dp[0] = 1;

        for(int i = 0; i < nums.size(); ++i) {
            for(int j = bag_size; j >= nums[i]; --j) {
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[bag_size];
    }
};
// @lc code=end

