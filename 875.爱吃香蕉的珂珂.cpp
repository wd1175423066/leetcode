/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = 0;
        for(int i = 0; i < piles.size(); ++i){
            r = max(piles[i], r);
        }
        int mid;
        while(l <= r){
            mid = l + (r - l) / 2;
            long time = calTime(piles, mid); // time should be long type
            if(time <= h){ // when time == h, speed can be smaller
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
    long calTime(const vector<int>& piles, const int speed){
        long time = 0;
        for(int i = 0; i < piles.size(); ++i){
            time += piles[i] / speed;
            time += piles[i] % speed == 0 ? 0 : 1;
        }
        return time;
    }
};
// @lc code=end

