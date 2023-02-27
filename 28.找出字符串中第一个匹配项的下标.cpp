/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) { 
        int h_len = haystack.size();
        int n_len = needle.size();
        for(int i = 0; i < h_len; ++i){
            if(haystack[i] == needle[0]){
                int m = i, n = 0;
                while(m < h_len && n < n_len) {
                    if(haystack[m] == needle[n]){
                        ++m;
                        ++n;
                    }
                    else{
                        break;
                    }
                }
                if(n == n_len) return i;
            }
        }
        return -1;
    }
};
// @lc code=end

