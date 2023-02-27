/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        auto get = [&](int i) -> pair<int, int>{
            if(i == -1 || i == nums.size()){
                return {0, 0};
            }
            else{
                return {1, nums[i]};
            }
        };
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(get(mid) > get(mid - 1) && get(mid) > get(mid + 1)){
                return mid;
            }
            else if(get(mid) < get(mid + 1)){
                l = mid + 1;//trace the plus direction, must find a anwser
            }
            else{
                r = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end

