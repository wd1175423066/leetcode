/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        const int m = mat.size();
        const int n = mat[0].size();
        vector<vector<int>> ans(m, vector<int>(n, INT_MAX));
        vector<vector<int>> seen(m, vector<int>(n, 0));
        queue<pair<int, int>> q;
        // init queue
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(mat[i][j] == 0){
                    q.push({i, j});
                    seen[i][j] = 1;
                }
            }
        }
        // bfs, from 0 cells to rest of the cells
        vector<int> dirs{0, -1, 0, 1, 0};
        int step = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                ans[x][y] = step;
                for(int k = 0; k < 4; ++k){
                    int nx = x + dirs[k];
                    int ny = y + dirs[k + 1];
                    if(nx < 0 || nx >= m || ny < 0 || ny >= n || seen[nx][ny]){
                        continue;
                    }
                    q.push({nx, ny});
                    seen[nx][ny] = 1;
                }

            }
            ++step;
        }
        return ans;
    }
};
// @lc code=end

