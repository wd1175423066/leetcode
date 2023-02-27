/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        // caculate number
        vector<int> numChars(128, 0);
        vector<bool> flag(128, false);
        for(char ch : t){
            flag[ch] = true;
            ++numChars[ch];
        }
        int cnt = 0;
        int min_size = s.size() + 1;
        int l = 0;
        int min_l = 0;
        for(int r = 0; r < s.size(); ++r){
            if(flag[s[r]]){
                if(--numChars[s[r]] >= 0){
                    ++cnt;
                }
                while(cnt == t.size()){
                    if(r - l + 1 < min_size){
                        min_size = r - l + 1;
                        min_l = l;
                    }
                    if(flag[s[l]] && ++numChars[s[l]] > 0){
                        --cnt;
                    }
                    ++l;
                }
            }
        }
        return min_size > s.size() ? "" : s.substr(min_l, min_size);
    }
};
// @lc code=end

