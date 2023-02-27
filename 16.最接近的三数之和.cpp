/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int max_delta = INT_MAX;
        int ans;
        const int n = nums.size();
        for(int i = 0; i < nums.size() - 2; ++i){ 
            int l = i + 1;
            int r = n - 1;
            while(l < r){
                int delta = nums[i] + nums[l] + nums[r] - target;
                if(abs(delta) < abs(max_delta)){
                    max_delta = delta;
                    ans = nums[i] + nums[l] + nums[r];
                }
                if(delta == 0){
                    return target;
                }
                else if(delta > 0){
                    --r;
                }
                else{
                    ++l;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

