/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        //dp[i] = max(dp[i - j] * j, (i - j) * j);
        dp[1] = 1;
        dp[2] = 1;
        for(int i = 3; i <= n; ++i) {
            for(int j = 1; j < i; ++j) {
                dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
            }
        }
        return dp[n];
    }
};
// @lc code=end

