/*
 * @lc app=leetcode.cn id=996 lang=cpp
 *
 * [996] 正方形数组的数目
 */

// @lc code=start
class Solution {
public:
    int numSquarefulPerms(vector<int>& nums) {
        const int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> cur;
        vector<int> used(n);
        int ans = 0;
        dfs(nums, used, cur, ans);
        return ans;
    }
private:
    bool squareful(int x, int y){
        int s = sqrt(x + y);
        return s * s == x + y;
    }
    void dfs(vector<int>& nums, vector<int>& used, vector<int>& cur, int& ans){
        if(cur.size() == nums.size()){
            ++ans;
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(used[i]){
                continue;
            }
            if(i > 0 && !used[i - 1] && nums[i - 1] == nums[i]){
                continue;
            }
            if(!cur.empty() && !squareful(cur.back(), nums[i])){
                continue;
            }
            cur.push_back(nums[i]);
            used[i] = 1;
            dfs(nums, used, cur, ans);
            used[i] = 0;
            cur.pop_back();
        }

    }
};
// @lc code=end

