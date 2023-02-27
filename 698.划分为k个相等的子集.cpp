/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % k != 0){
            return false;
        }
        sort(nums.rbegin(), nums.rend());
        return dfs(nums, sum / k, 0, 0, k);
    }
private:
    bool dfs(vector<int>& nums, int target, int used, int cur, int k){
        if(k == 0){
            return used == (1 << nums.size()) - 1;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(used & (1 << i)){
                continue;
            }
            int t = cur + nums[i];
            if(t > target){
                break;
            }
            int new_used = used | (1 << i);
            if(t == target && dfs(nums, target, new_used, 0, k - 1)){
                return true;
            }
            else if(dfs(nums, target, new_used, t, k)){
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

