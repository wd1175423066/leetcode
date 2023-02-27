/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */

// @lc code=start
class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> counts;
        for(const int & num : nums){
            ++counts[num];
        }
        int index = 0;
        for(const auto & p : counts){
            for(int i = 0; i < p.second; ++i){
                nums[index++] = p.first;
            }
        }
    }
};
// @lc code=end

