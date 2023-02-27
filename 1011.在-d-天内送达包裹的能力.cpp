/*
 * @lc app=leetcode.cn id=1011 lang=cpp
 *
 * [1011] 在 D 天内送达包裹的能力
 */

// @lc code=start
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 0;
        int r = 0;
        for(int i = 0; i < weights.size(); ++i){
            l = max(l, weights[i]);
            r += weights[i];
        }
        while(l <= r){
            int mid = l + (r - l) / 2;
            int cur_day = calDays(weights, mid);
            if(cur_day <= days){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
    int calDays(vector<int>& weights, int max_load){
        int day = 0;
        int cur_load = 0;
        for(int i = 0; i < weights.size(); ++i){
            if(cur_load + weights[i] > max_load){
                ++day;
                cur_load = weights[i];
            }
            else{
                cur_load += weights[i];
            }
        }
        return day + 1;
    }
};
// @lc code=end

