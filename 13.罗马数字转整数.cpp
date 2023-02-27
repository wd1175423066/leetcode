/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        map<char, int> rome = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int result = 0;
        int index = 0;
        int size = s.size();
        while(index < size - 1){
            if(rome[s[index]] >= rome[s[index + 1]]){
                result += rome[s[index]];
                ++index;
            }
            else{
                result += rome[s[index + 1]] - rome[s[index]];
                index += 2;
            }
        }
        if(index == size - 1) result += rome[s[index]];
        return result;
    }
};
// @lc code=end

