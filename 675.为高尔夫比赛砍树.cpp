/*
 * @lc app=leetcode.cn id=675 lang=cpp
 *
 * [675] 为高尔夫比赛砍树
 */

// @lc code=start
class Solution {
public:
    int cutOffTree(vector<vector<int>>& forest) {
        vector<tuple<int, int, int>> trees;
        m_ = forest.size();
        n_ = forest[0].size();
        // insert tree info
        for(int i = 0; i < m_; ++i){
            for(int j = 0; j < n_; ++j){
                if(forest[i][j] > 1){
                    trees.emplace_back(forest[i][j], i, j);
                }
            }
        }
        //sort trees
        sort(trees.begin(), trees.end());
        int sx = 0;
        int sy = 0;
        //move from current to target
        int step = 0;
        int total_step = 0;
        for(int i = 0; i < trees.size(); ++i){
            int tx = get<1>(trees[i]);
            int ty = get<2>(trees[i]);
            step = BFS(forest, sx, sy, tx, ty);
            if(step == INT_MAX){
                return -1;
            }
            total_step += step;
            sx = tx;
            sy = ty;
        }
        return total_step;

    }
private:
    int m_;
    int n_;
    int BFS(vector<vector<int>>& forest, int sx, int sy, int tx, int ty){
        vector<int> dirs{-1, 0, 1, 0, -1};
        vector<vector<int>> visited(m_, vector<int>(n_, 0));
        queue<pair<int, int>> q;
        q.push({sx, sy});
        visited[sx][sy] = 1;
        int step = 0;

        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto p = q.front();
                q.pop();
                int cx = p.first;
                int cy = p.second;
                if(cx == tx && cy == ty){
                    return step;
                }
                for(int k = 0; k < 4; ++k){
                    int x = cx + dirs[k];
                    int y = cy + dirs[k + 1];
                    if(x < 0 || x >= m_ || y < 0 || y >= n_ || visited[x][y] || !forest[x][y]){
                        continue;
                    }
                    visited[x][y] = 1;
                    q.push({x, y});
                }
            }
            ++step;
        }
        return INT_MAX;
    }
};
// @lc code=end

