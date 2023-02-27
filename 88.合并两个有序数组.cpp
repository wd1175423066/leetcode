/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // set pointer
        int pos =  m + n - 1;
        --m;
        --n;
        while(m >=0 && n >=0) {
            if(nums2[n] >= nums1[m]){
                nums1[pos] = nums2[n];
                --pos;
                --n;
            }
            else{
                nums1[pos] = nums1[m];
                --pos;
                --m;
            }
        }
        while(n >= 0 ){
            nums1[pos] = nums2[n];
            --pos;
            --n;
        }
    }
};
// @lc code=end

