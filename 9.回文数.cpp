/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        long temp_x = x;
        if(x < 0) return false;
        long i_x = 0;
        long pos = 0;
        while(x){
            pos = x % 10;
            x /= 10;
            i_x = 10 * i_x + pos;
        }
        if(temp_x == i_x) return true;
        else return false;
    }
};
// @lc code=end

