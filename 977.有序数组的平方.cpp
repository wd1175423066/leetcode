/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int i = 0;
        int j = n - 1;
        int pos = n - 1;
        while(i <= j){
            if(nums[i] * nums[i] > nums[j] * nums[j]){
                ans[pos] = nums[i] * nums[i];
                ++i;
            }
            else{
                ans[pos] = nums[j] * nums[j];
                --j;
            }
            --pos;
        }
        return ans;
    }
};
// @lc code=end

