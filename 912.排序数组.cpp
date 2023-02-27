/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> tmp(nums.size());
        function<void(int, int)> mergeSort = [&](int l, int r){
            if(l + 1 == r){
                return;
            }
            int m = l + (r - l) / 2;
            mergeSort(l, m);
            mergeSort(m, r);
            int il = l;
            int ir = m;
            int index = 0;
            while(il < m || ir < r){
                if(ir == r || (il < m && nums[il] < nums[ir])){
                    tmp[index++] = nums[il++];
                }
                else{
                    tmp[index++] = nums[ir++];
                }
            }
            std::copy(tmp.begin(), tmp.begin() + index, nums.begin() + l);
        };
        mergeSort(0, nums.size());
        return nums;
    }
};
// @lc code=end

