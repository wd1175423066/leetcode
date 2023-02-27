/*
 * @lc app=leetcode.cn id=680 lang=cpp
 *
 * [680] 验证回文串 II
 */

// @lc code=start
class Solution {
public:
    bool isPal(string s, int i, int j){
        while(i < j){
            if(s[i] != s[j]) return false;
            else{
                ++i;
                --j;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while(l < r){
            if(s[l] != s[r]){
                return isPal(s, l+1, r) || isPal(s, l , r-1);
            }
            else{
                ++l;
                --r;
            }
        }
        return true;
    }
};
// @lc code=end

