/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), mid;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(target == nums[mid]){
                return true;
            }
            if(nums[mid] > nums[l]){
                if(target >= nums[l] && target < nums[mid]){
                    r = mid;
                }
                else{
                    l = mid + 1;
                }
            }
            else if(nums[mid] < nums[l]){
                if(target > nums[mid] && target < nums[l]){
                    l = mid + 1;
                }
                else{
                    r = mid;
                }
            }
            else{
                ++l;
            }
        }
        return false;
    }
};
// @lc code=end

