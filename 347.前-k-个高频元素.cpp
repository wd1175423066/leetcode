/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @lc code=start
class Solution {
    class com{
        public:
            bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
                return a.second > b.second;
            }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> counts;
        for(const int & num : nums){
            ++counts[num];
        }
        // generate priority_queue
        priority_queue<pair<int, int>, vector<pair<int, int>>, com> pri_q;

        for(auto it = counts.begin(); it != counts.end(); ++it) {
            pri_q.push(*it);
            if(pri_q.size() > k) pri_q.pop();
        }

        vector<int> res(k);
        for(int i = k - 1; i >= 0; --i) {
            res[i] = pri_q.top().first;
            pri_q.pop();
        }
        
        return res;
    }
};
// @lc code=end

