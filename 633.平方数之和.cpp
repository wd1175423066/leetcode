/*
 * @lc app=leetcode.cn id=633 lang=cpp
 *
 * [633] 平方数之和
 */

// @lc code=start
class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0;
        long b = sqrt(c);
        while(a <= b){
            long sum = a * a + b * b;
            if(sum == c) return true;
            else if(sum < c){
                ++a;
            }
            else{
                --b;
            }
        }
        return false;
    }
};
// @lc code=end

