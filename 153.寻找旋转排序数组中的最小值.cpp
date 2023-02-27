/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        // return findMin(nums, 0, nums.size() - 1);
        int min = INT_MAX;
        int l = 0;
        int r = nums.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] < min){
                min = nums[mid];
            }
            if(nums[mid] < nums[l]){
                r = mid - 1;
            }
            else{
                if(nums[mid] > nums[r]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
        }
        return min;
    }
    // int findMin(const vector<int>& nums, int l, int r){
    //     if(l == r){
    //         return nums[l];
    //     }
    //     int m = l + (r - l) / 2;
    //     const int ml = findMin(nums, l, m);
    //     const int mr = findMin(nums, m + 1, r);
    //     return ml <= mr ? ml : mr;
    // }
};
// @lc code=end

