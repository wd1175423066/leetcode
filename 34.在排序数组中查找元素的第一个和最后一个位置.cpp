/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()) return {-1, -1};
        return {lower_bound(nums, target), upper_bound(nums, target)};
    }


    int lower_bound(const vector<int>& nums, int target){
        int l = 0;
        int r = nums.size();
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        if(l == nums.size() || nums[l] != target){
            return -1;
        }
        return l;
    }

    int upper_bound(const vector<int>& nums, int target){
        int l = 0;
        int r = nums.size();
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] <= target){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        --l; // l points to the first which is bigger than target
        if(l < 0 || nums[l] != target){
            return -1;
        }
        return l;
    }
};
// @lc code=end

