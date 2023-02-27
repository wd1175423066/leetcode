/*
 * @lc app=leetcode.cn id=986 lang=cpp
 *
 * [986] 区间列表的交集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        size_t i = 0;
        size_t j = 0;
        vector<vector<int>> ans;
        while(i < firstList.size() && j < secondList.size()){
            int s = max(firstList[i][0], secondList[j][0]);
            int e = min(firstList[i][1], secondList[j][1]);
            if(s <= e){
                ans.push_back({s, e});
            }
            if(firstList[i][1] < secondList[j][1]){
                ++i;
            }
            else{
                ++j;
            }
        }
        return ans;
    }
};
// @lc code=end

