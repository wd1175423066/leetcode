/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        int flag = 0;
        for(int i = len - 1; i >=0; --i){
            digits[i] = digits[i] + 1;
            flag = digits[i] / 10;
            digits[i] %= 10;
            if(!flag) return digits;
        }
        if(flag == 1) digits.insert(digits.begin(), 1);
        return digits;
    }
};
// @lc code=end

