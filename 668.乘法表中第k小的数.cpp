/*
 * @lc app=leetcode.cn id=668 lang=cpp
 *
 * [668] 乘法表中第k小的数
 */

// @lc code=start
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l = 1;
        int r = m * n + 1;
        while(l < r){
            int mid = l + (r - l) / 2;
            int smallNum = calSmallNum(m, n, mid);
            if(smallNum < k){
                l = mid + 1;
            }
            else if(smallNum > k){
                r = mid;
            }
            else{
                r = mid;
            }
        }
        return l;
    }
    int calSmallNum(const int m, const int n, int target){
        int i = m;
        int j = 1;
        int total = 0;
        while(i >= 1 && j <= n){
            if(i * j <= target){
                total += i;
                ++j;
            }
            else{
                --i;
            }
        }
        return total;
    }
};
// @lc code=end

