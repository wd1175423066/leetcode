/*
 * @lc app=leetcode.cn id=917 lang=cpp
 *
 * [917] 仅仅反转字母
 */

// @lc code=start
class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i = 0;
        int j = s.length() - 1;
        while(i < j){
            if(isalpha(s[i]) && isalpha(s[j])){
                swap(s[i], s[j]);
                ++i;
                --j;
            }
            else{
                if(!isalpha(s[i])){
                    ++i;
                }
                else{
                    --j;
                }
            }
        }
        return s;
    }
};
// @lc code=end

