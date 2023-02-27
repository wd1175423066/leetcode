/*
 * @lc app=leetcode.cn id=167 lang=cpp
 *
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int index1 = 0;
        int index2 = numbers.size() - 1;
        while(index1 < index2){
            int sum = numbers[index1] + numbers[index2];
            if(sum == target) break;
            else if(sum < target) ++index1;
            else --index2;
        }
        return {index1 + 1, index2 + 1};
    }
};
// @lc code=end

