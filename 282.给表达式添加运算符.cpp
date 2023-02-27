/*
 * @lc app=leetcode.cn id=282 lang=cpp
 *
 * [282] 给表达式添加运算符
 */

// @lc code=start
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> ans;
        dfs(num, target, 0, "", 0, 0, ans);
        return ans;
    }
    void dfs(const string& num, const int target, int pos, string exp, long prev, long cur, vector<string>& ans){
        if(pos == num.size()){
            if(target == cur){
                ans.push_back(exp);
            }
            return;
        }
        for(int i = 1; i <= num.size() - pos; ++i){
            string t = num.substr(pos, i);
            if(t[0] == '0' && t.length() > 1){
                break;
            }
            long n = std::stol(t);
            if(n > INT_MAX){
                break;
            }
            if(pos == 0){
                dfs(num, target, i, t, n, n, ans);
                continue;
            }
            dfs(num, target, pos + i, exp + '+' + t, n, cur + n, ans);
            dfs(num, target, pos + i, exp + '-' + t, -n, cur - n, ans);
            dfs(num, target, pos + i, exp + '*' + t, prev * n, cur - prev + prev * n, ans);
        }
    }
};
// @lc code=end

