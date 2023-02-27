/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k + 1, 0));
        // init
        for(int i = 0; i < k; ++i){
            dp[0][2 * i + 1] = -prices[0];
        }
        // iterative
        for(int i = 1; i < n; ++i){
            for(int j = 1; j < 2  * k + 1; j += 2){
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i]);
                dp[i][j + 1] = max(dp[i - 1][j + 1],  dp[i - 1][j] + prices[i]);
            }
        }
        return dp[n - 1][2 * k];
    }
};
// @lc code=end

