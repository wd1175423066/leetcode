/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len_strs = strs.size();
        int len_str0 = strs[0].size();
        for(int i = 0; i < len_str0; ++i){
            char c = strs[0][i];
            for(int j = 1; j < len_strs; ++j){
                // judge whether strs[j].size() is bigger than index i, when not satisfy then return 
                if(i == int(strs[j].size()) || strs[j][i] != c){
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
// @lc code=end

