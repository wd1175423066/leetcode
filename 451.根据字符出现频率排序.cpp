/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> counts;
        int max_count = 0;
        for(const char & ch : s){
            max_count = max(max_count, ++counts[ch]);
        }
        vector<vector<char>> buckets(max_count + 1);
        for(const auto & p : counts){
            buckets[p.second].push_back(p.first);
        }
        string ans;
        for(int i = max_count; i > 0; --i){
            for(const char & ch : buckets[i]){
                for(int j = 0; j < i; ++j){
                    ans += ch;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

