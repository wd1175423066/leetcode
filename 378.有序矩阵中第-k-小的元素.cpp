/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int l = matrix[0][0];
        int r = matrix[n - 1][n - 1] + 1;
        int mid;
        while(l < r){
            mid = l + (r - l) / 2;
            int smallNum = calSmallNum(matrix, mid);
            if(smallNum > k){
                r = mid;
            }
            else if(smallNum < k){
                l = mid + 1;
            }
            else{
                r = mid;
            }
        }
        return l;
    }
    int calSmallNum(const vector<vector<int>>& matrix, int target){
        //nice idea, O(n) alg to check the num of numbers smaller than target
        int n = matrix.size();
        int i = n - 1;
        int j = 0;
        int total = 0;
        while(i >= 0 && j < n){
            if(matrix[i][j] <= target){
                total += i + 1;
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

