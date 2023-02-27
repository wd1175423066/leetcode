/*
 * @lc app=leetcode.cn id=524 lang=cpp
 *
 * [524] 通过删除字母匹配到字典里最长单词
 */

// @lc code=start
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        // sort 
        sort(dictionary.begin(), dictionary.end(), [](const string& s1, const string& s2){return s1.size() > s2.size() || (s1.size() == s2.size() &&s1 < s2);});
        
        // two pointer search
        int s_len = s.size();
        for(const string& d : dictionary){
            int d_len = d.size();
            int i = 0, j = 0;
            while(i < s_len && j < d_len){
                if(s[i] == d[j]){
                    ++i;
                    ++j;
                }
                else{
                    ++i;
                }
            }
            if(j == d_len) return d;
        }
        return "";

    }
};
// @lc code=end

