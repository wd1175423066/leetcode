/*
 * @lc app=leetcode.cn id=547 lang=cpp
 *
 * [547] 省份数量
 */

// @lc code=start
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), count = 0;
        vector<bool> isVisited(n, false);
        for(int i = 0; i < n; ++i){
            if(!isVisited[i]){
                dfs(isConnected, isVisited, i);
                ++count;
            }
        }
        return count;
    }

    void dfs(vector<vector<int>> & isConnected, vector<bool> & isVisited, int i){
        isVisited[i] = true;
        for(int k = 0; k < isConnected.size(); ++k){
            if(isConnected[i][k] == 1 && !isVisited[k]){
                dfs(isConnected, isVisited, k);
            }
        }
    }
};
// @lc code=end

