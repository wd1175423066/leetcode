/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 */

// @lc code=start
class Solution {
public:
    vector<int> direction{-1, 0, 1, 0, -1};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        // stack
        // vector<int> direction{-1, 0, 1, 0, -1};
        // int m = grid.size();
        // int n = m ? grid[0].size() : 0;
        // int local_area = 0, max_area = 0, x, y;
        // for(int i = 0; i < m; ++i){
        //     for(int j = 0; j < n; ++j){
        //         if(grid[i][j]){
        //             local_area = 1;
        //             grid[i][j] = 0;
        //             stack<pair<int, int>> island;
        //             island.push({i, j});
        //             while(!island.empty()){
        //                 auto [r, c] = island.top();
        //                 island.pop();
        //                 for(int k = 0; k < 4; ++k){
        //                     x = r + direction[k];
        //                     y = c + direction[k + 1];
        //                     if(x >= 0 && x < m && y >= 0 && y < n && grid[x][y]){
        //                         ++local_area;
        //                         grid[x][y] = 0;
        //                         island.push({x, y});
        //                     }
        //                 }
        //             }
        //         }
        //         max_area = max(max_area, local_area);
        //     }
        // }
        // return max_area;

        // recursive
        if(grid.empty() || grid[0].empty()) return 0;
        int max_area = 0;
        for(size_t i = 0; i < grid.size(); ++i){
            for(size_t j = 0; j < grid[0].size(); ++j){
                max_area = max(max_area, dfs(grid, i, j));
            }
        }
        return max_area;
    }

    int dfs(vector<vector<int>> & grid, int r, int c){
        if(grid[r][c] == 0) return 0;
        grid[r][c] = 0;
        int x, y, local_area = 1;
        for(int k = 0; k < 4; ++k){
            x = r + direction[k];
            y = c + direction[k + 1];
            if(x >=0 && x < grid.size() && y >= 0 && y < grid[0].size()){
                local_area += dfs(grid, x, y);
            }
        }
        return local_area;
    }
};
// @lc code=end

