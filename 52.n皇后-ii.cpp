/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 */

// @lc code=start
class Solution {
public:
    int totalNQueens(int n) {
        vector<int> cols(n);
        vector<int> diag1(2 * n - 1);
        vector<int> diag2(2 * n - 1);
        int ans = 0;
        function<void(int)> dfs = [&](int d){
            if(d == n){
                ++ans;
            }
            for(int i = 0; i < n; ++i){
                if(cols[i] || diag1[n - d + i - 1] || diag2[i + d]){
                    continue;
                }
                cols[i] = 1;
                diag1[n - d + i - 1] = 1;
                diag2[i + d] = 1;
                dfs(d + 1);
                cols[i] = 0;
                diag1[n - d + i - 1] = 0;
                diag2[i + d] = 0;
            }
        };
        dfs(0);
        return ans;
    }
};
// @lc code=end

