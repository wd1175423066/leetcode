/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        // can deal with it directly
        int l = 0;
        int r = s.length() - 1;
        while(l < r){
            if(!isalnum(s[l])){
                ++l;
                continue;
            }
            if(!isalnum(s[r])){
                --r;
                continue;
            }
            if(tolower(s[l]) == tolower(s[r])){
                ++l;
                --r;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

