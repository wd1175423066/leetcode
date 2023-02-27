/*
 * @lc app=leetcode.cn id=934 lang=cpp
 *
 * [934] 最短的桥
 */

// @lc code=start
class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        //dfs找到第一个岛屿
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> points;
        bool flipped = false;
        for(int i = 0; i < m; ++i){
            if(flipped){
                break;
            }
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1){
                    dfs(grid, points, i, j, m, n);
                    flipped = true;
                    break;
                }
            }
        }

        //bfs找第二个岛屿
        int x, y;
        int level = 0;
        vector<int> direction{-1, 0, 1, 0, -1};
        while(!points.empty()){
            ++level;
            int n_points = points.size();
            while(n_points--){
                auto [r, c] = points.front();
                points.pop();
                for(int k = 0; k < 4; ++k){
                    x = r + direction[k];
                    y = c + direction[k + 1];
                    if(x >= 0 && x < m && y >= 0 && y < n){
                        if(grid[x][y] == 1){
                            return level;
                        }
                        if(grid[x][y] == 2){
                            continue;
                        }
                        points.push({x, y});
                        grid[x][y] = 2;
                    }
                }
            }
        }
        return 0;
    }

    void dfs(vector<vector<int>>& grid, queue<pair<int, int>>& points, int i, int j, int m, int n){
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 2){
            return;
        }
        if(grid[i][j] == 0){
            points.push({i, j});
            return;
        }
        grid[i][j] = 2;
        dfs(grid, points, i + 1, j, m, n);
        dfs(grid, points, i - 1, j, m, n);
        dfs(grid, points, i, j + 1, m, n);
        dfs(grid, points, i, j - 1, m, n);
    }
};
// @lc code=end

