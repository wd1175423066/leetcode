/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string cur;
        if(n > 0){
            dfs(n, n, cur, ans);
        }
        return ans;
    }
    void dfs(int l, int r, const string cur, vector<string>& ans){
        if(l + r == 0){
            ans.push_back(cur);
            return;
        }
        if(r < l){
            return;
        }
        if(l > 0){
            dfs(l - 1, r, cur + '(', ans);
        }
        if(r > 0){
            dfs(l, r - 1, cur + ')', ans);
        }
    }
};
// @lc code=end

