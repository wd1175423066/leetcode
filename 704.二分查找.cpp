/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
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
            else if(nums[mid] > target){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        if(l == nums.size() || nums[l] != target){
            return -1;
        }
        return l;
    }
};
// @lc code=end

