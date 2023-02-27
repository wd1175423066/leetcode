/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0){
            return 0;
        }
        long l = 1;
        long r = x;
        long mid = 0;
        while(l <= r){
            mid = l + (r - l) / 2;
            if(mid * mid == x){
                return mid;
            }
            else if(mid * mid < x){
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return r;
    }
};
// @lc code=end

