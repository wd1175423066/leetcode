/*
 * @lc app=leetcode.cn id=35 lang=cpp
 *
 * [35] 搜索插入位置
 */

// @lc code=start
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r= nums.size();
        while(l < r){
            int mid = l + (r - l) / 2;
            if(target == nums[mid]){
                return mid;
            }
            else if(nums[mid] < target){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return l;
    }
};
// @lc code=end

