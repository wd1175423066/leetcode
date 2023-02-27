/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // binary search O(log(m+n))
        int n1 = nums1.size();
        int n2 = nums2.size();
        int left = (n1 + n2 + 1) / 2;
        int right = (n1 + n2 + 2) / 2;
        return (getKth(nums1, 0, n1 - 1, nums2, 0, n2 - 1, left) + getKth(nums1, 0, n1 - 1, nums2, 0, n2 - 1, right)) / 2.0;
    }
    int getKth(vector<int>& nums1, int begin1, int end1, vector<int>& nums2, int begin2, int end2, int k){
        int len1 = end1 - begin1 + 1;
        int len2 = end2 - begin2 + 1;
        if(len1 > len2){
            return getKth(nums2, begin2, end2, nums1, begin1, end1, k);
        }
        if(len1 == 0){
            return nums2[begin2 + k - 1]; // begin2 + k - 1
        }
        if(k == 1){
            return min(nums1[begin1], nums2[begin2]);
        }
        int i = begin1 + min(k / 2, len1) - 1;
        int j = begin2 + min(k / 2, len2) - 1;
        if(nums1[i] < nums2[j]){
            return getKth(nums1, i + 1, end1, nums2, begin2, end2, k - (i - begin1 + 1));
        }
        else{
            return getKth(nums1, begin1, end1, nums2, j + 1, end2, k - (j - begin2 + 1));
        }
    }
};
// @lc code=end

