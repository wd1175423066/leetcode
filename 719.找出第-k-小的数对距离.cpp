/*
 * @lc app=leetcode.cn id=719 lang=cpp
 *
 * [719] 找出第 K 小的数对距离
 */

// @lc code=start
class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = INT_MAX;
        for(int i = 1; i < n; ++i){
            l = min(l, nums[i] - nums[i - 1]);
        }
        int r = nums[n - 1] + nums[0] + 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            int smallNum = calSmallNum(nums, mid);
            if(smallNum < k){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return l;
    }
    int calSmallNum(vector<int>& nums, int target){
        int n = nums.size();
        int i = 0;
        int j = 1;
        int ans = 0;
        while(i < n && j < n){
            int dis = nums[j] - nums[i];
            if(dis <= target){
                ans += (j - i);
                ++j;
            }
            else{
                if(j - i > 1){
                    ++i;
                }
                else{
                    ++j;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

