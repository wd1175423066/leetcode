/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        int count = 0;
        int index = len - 1;
        while(index >= 0 && s[index] == ' '){
            --index;
        }
        while(index >= 0 && s[index] != ' '){
            ++count;
            --index;
        }
        return count;
    }
};
// @lc code=end

