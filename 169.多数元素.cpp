/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majorityElement(nums, 0, nums.size() - 1);
    }
    int majorityElement(const vector<int>& nums, int l, int r){
        if(l == r){
            return nums[l];
        }
        int m = l + (r - l) / 2;
        int ml = majorityElement(nums, l, m);
        int mr = majorityElement(nums, m + 1, r);
        if(ml == mr){
            return ml;
        }
        return count(nums.begin() + l, nums.begin() + r + 1, ml) > count(nums.begin() + l, nums.begin() + r + 1, mr) ? ml : mr;
    }
};
// @lc code=end

