/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        // over time
        // if(n == 1) return 1;
        // if(n == 2) return 2;
        // return climbStairs(n - 1) + climbStairs(n - 2);
        // a[n] = a[n-1] + a[n-2]
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        for(int j = 1; j <= n; ++j) {
            for(int i = 1; i <= 2; ++i) {
                if(j - i >= 0) dp[j] += dp[j - i];
            }
        } 
        return dp[n];
    }
};
// @lc code=end

