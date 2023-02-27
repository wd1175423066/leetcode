/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        vector<int> tmp(nums.size());
        vector<int> map(nums.size()); //index array
        vector<int> t_map(nums.size()); //tmp index array , update when merge to get index of num
        for(int i = 0; i < nums.size(); ++i){
            map[i] = i;
        }
        function<void(int, int)> mergeSort = [&](int l, int r){
            if(l + 1 >= r){
                return;
            }
            int m = l + (r - l) / 2;
            mergeSort(l, m);
            mergeSort(m, r);
            int il = l;
            int ir = m;
            int index = 0;
            while(il < m || ir < r){
                if(ir == r || (il < m && nums[il] <= nums[ir])){
                    tmp[index] = nums[il];
                    t_map[index] = map[il];
                    ans[map[il]] += (ir - m);
                    ++index; ++il;
                }
                else{
                    tmp[index] = nums[ir];
                    t_map[index] = map[ir];
                    ++index; ++ir;
                }
            }
            std::copy(tmp.begin(), tmp.begin() + index, nums.begin() + l);
            std::copy(t_map.begin(), t_map.begin() + index, map.begin() + l);
        };
        mergeSort(0, nums.size());
        return ans;
    }
};
// @lc code=end

