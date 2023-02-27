/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        // int n = height.size();
        // int ans = 0;
        // auto sit = cbegin(height);
        // auto eit = cend(height);
        // for(int i = 0; i < n; ++i){
        //     int l = *max_element(sit, sit + i + 1); //include i itself
        //     int r = *max_element(sit + i, eit);
        //     ans += min(l, r) - height[i];
        // }
        // return ans;
        int l = 0;
        int r = height.size() - 1;
        int max_l = height[l];
        int max_r = height[r];
        int ans = 0;
        while(l < r){
            if(max_l < max_r){
                ans += max_l - height[l];
                ++l;
                max_l = max(max_l, height[l]);
            }
            else{
                ans += max_r - height[r];
                --r;
                max_r = max(max_r, height[r]);
            }
        }
        return ans;
    }
};
// @lc code=end

