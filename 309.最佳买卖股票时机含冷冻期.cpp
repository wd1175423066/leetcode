/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 最佳买卖股票时机含冷冻期
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][1] = -prices[0];
        for(int i = 1; i < n; ++i){
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3] - prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
            dp[i][3] = dp[i - 1][2];
        }
        return max(dp[n - 1][2], dp[n - 1][3]);
    }
};
// @lc code=end

