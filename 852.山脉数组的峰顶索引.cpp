/*
 * @lc app=leetcode.cn id=852 lang=cpp
 *
 * [852] 山脉数组的峰顶索引
 */

// @lc code=start
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0;
        int r = arr.size() - 1;
        while(l <= r){
            int mid = l + (r - l) / 2;
            if(arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1]){
                return mid;
            }
            else if(arr[mid] > arr[mid + 1]){
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return -1;
    }
};
// @lc code=end

