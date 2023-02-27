/*
 * @lc app=leetcode.cn id=925 lang=cpp
 *
 * [925] 长按键入
 */

// @lc code=start
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0;
        int j = 0;
        while(i < name.length() && j < typed.length()){
            if(name[i] == typed[j]){
                ++i;
                ++j;
            }
            else if(j > 0 && typed[j] == typed[j - 1]){
                ++j;
            }
            else{
                return false;
            }
        }
        while(j < typed.length() && typed[j - 1] == typed[j]){
            ++j;
        }
        return i == name.length() && j == typed.length();
    }
};
// @lc code=end

