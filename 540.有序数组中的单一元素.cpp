/*
 * @lc app=leetcode.cn id=540 lang=cpp
 *
 * [540] 有序数组中的单一元素
 */

// @lc code=start
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1, mid;
        while(l < r){
            mid = l + (r - l) / 2;
            if(mid % 2 == 1){
                if(nums[mid] == nums[mid - 1]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            else{
                if(nums[mid] == nums[mid + 1]){
                    l = mid + 2; //key
                }
                else{
                    r = mid;
                }
            }
        }
        return nums[l];
    }
};
// @lc code=end

