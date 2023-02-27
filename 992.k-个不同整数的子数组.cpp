/*
 * @lc app=leetcode.cn id=992 lang=cpp
 *
 * [992] K 个不同整数的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return maxKDifferent(nums, k) - maxKDifferent(nums, k - 1); // 
    }
    int maxKDifferent(const vector<int>& nums, const int k){ //subarray which has at most k different element in nums
        int n = nums.size();
        vector<int> count(n + 1);
        int distinct = 0;
        int l = 0;
        int r = 0;
        int res = 0;
        while(r < n){
            if(count[nums[r]] == 0){
                ++distinct;
            }
            ++count[nums[r]];
            while(distinct > k){
                --count[nums[l]];
                if(count[nums[l]] == 0){
                    --distinct;
                }
                ++l;
            }
            res += r - l + 1;
            ++r;
        }
        return res;
    }
};
// @lc code=end

