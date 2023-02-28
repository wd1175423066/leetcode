/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        if(s.size() % 2 != 0) return false;
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '(') stk.push(')');
            else if(s[i] == '{') stk.push('}');
            else if(s[i] == '[') stk.push(']');
            else{
                if(!stk.empty() && s[i] == stk.top()) stk.pop();
                else return false;
            }
        }
        return stk.empty();
    }
};
// @lc code=end

