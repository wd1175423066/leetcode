/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        /*
            ';'after map
            stk.pop(),top()
        */
        map<char, int> bracket{
            {'(', 1},
            {')', -1},
            {'[', 2},
            {']', -2},
            {'{', 3},
            {'}', -3},
        };
        stack<char> stk;
        int len = s.size();
        for(int i = 0; i < len; ++i){
            if(bracket[s[i]] > 0){
                stk.push(s[i]);
            }
            else{
                if(stk.empty() || bracket[stk.top()] + bracket[s[i]] != 0){
                    return false;
                }
                stk.pop();
            }
        }
        if(stk.empty()) return true;
        else return false;

    }
};
// @lc code=end

