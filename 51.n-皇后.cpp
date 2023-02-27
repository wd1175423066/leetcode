/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        //使用单个数组对每列、斜杠进行编号
        vector<bool> column(n), ldiag(2 * n - 1), rdiag(2 * n - 1);
        int y = 0;
        backtracking(ans, board, column, ldiag, rdiag, y, n);
        return ans;
    }

    void backtracking(vector<vector<string>>& ans, vector<string>& board, vector<bool>& column, vector<bool>& ldiag, vector<bool>& rdiag, int y, int n){
        if(y == n){
            ans.push_back(board);
            return;
        }
        for(int x = 0; x < n; ++x){
            if(column[x] || ldiag[n - x + y - 1] || rdiag[x + y]){
                continue;
            }
            board[y][x] = 'Q';
            column[x] = true;
            ldiag[n - x + y - 1] = true;
            rdiag[x + y] = true;

            backtracking(ans, board, column, ldiag, rdiag, y + 1, n);

            board[y][x] = '.';
            column[x] = false;
            ldiag[n - x + y - 1] = false;
            rdiag[x + y] = false;
        }
    }

};
// @lc code=end

