/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> stk;
        for(int i = 0; i < s.size(); ++i) {
            if(stk.empty() || s[i] != stk.top()) stk.push(s[i]);
            else stk.pop();
        }
        string res;
        while(!stk.empty()) {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
// @lc code=end

