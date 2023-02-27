/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        int n = s.size();
        vector<string> ans;
        function<void(int)> dfs = [&](int d){
            if(d == n){
                ans.push_back(s);
                return;
            }
            dfs(d + 1);
            if(!isalpha(s[d])){
                return;
            }
            s[d] ^= (1 << 5);
            dfs(d + 1);
            s[d] ^= (1 << 5);
            
        };
        dfs(0);
        return ans;
    }
};
// @lc code=end

