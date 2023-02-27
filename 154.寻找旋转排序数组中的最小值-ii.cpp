/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        // return findMin(nums, 0, nums.size() - 1);
        int l = 0;
        int r = nums.size() - 1;
        int min = INT_MAX;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(nums[mid] < min){
                min = nums[mid];
            }
            if(nums[mid] < nums[l]){
                r = mid - 1;
            }
            else if(nums[mid] > nums[l]){
                if(nums[mid] > nums[r]){
                    l = mid + 1;
                }
                else if(nums[mid] < nums[r]){
                    r = mid - 1;
                }
                else{
                    --r;
                }
            }
            else{
                ++l;
            }
        }
        return min;
    }
    // int findMin(vector<int>& nums, int l, int r){
    //     if(l == r){
    //         return nums[l];
    //     }
    //     int m = l + (r - l) / 2;
    //     int ml = findMin(nums, l, m);
    //     int mr = findMin(nums, m + 1, r);
    //     return ml <= mr ? ml : mr;
    // }
};
// @lc code=end

