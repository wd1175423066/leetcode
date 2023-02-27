/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] == target){
                return mid;
            }
            if(nums[l] < nums[mid]){
                if(target < nums[mid] && target >= nums[l]){ //left area inlcudes nums[l]
                    r = mid;
                }
                else{
                    l = mid + 1;
                }
            }
            else{
                if(target > nums[mid] && target < nums[l]){
                    l = mid + 1;
                }
                else{
                    r = mid;
                }
            }
        }
        return -1;
    }
};
// @lc code=end

