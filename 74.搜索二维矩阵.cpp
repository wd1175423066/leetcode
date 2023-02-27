/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //col binary search
        int l = 0;
        int r = matrix.size();
        int mid;
        while(l < r){
            mid = l + (r - l) / 2;
            if(matrix[mid][0] == target){
                return true;
            }
            else if(matrix[mid][0] > target){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        //row binary search
        int row = l - 1;
        if(row < 0){ // judge overflow bug
            return false;
        }
        l = 0;
        r = matrix[row].size();
        while(l < r){
            mid = l + (r - l) / 2;
            if(matrix[row][mid] == target){
                return true;
            }
            else if(matrix[row][mid] > target){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return false;
    }
};
// @lc code=end

