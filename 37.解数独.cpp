/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 */

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        // build judge vector
        vector<vector<int>> rows_(9, vector<int>(10));
        vector<vector<int>> cols_(9, vector<int>(10));
        vector<vector<int>> boxes_(9, vector<int>(10));
        // fill the vector
        // x means rows, y means cols, x/3 *3 + y/3 means boxes
        for(int i = 0; i < 9; ++i){
            for(int j = 0; j < 9; ++j){
                if(board[i][j] != '.'){
                    int n = board[i][j] - '0';
                    rows_[i][n] = 1;
                    cols_[j][n] = 1;
                    boxes_[i / 3 * 3 + j / 3][n] = 1;
                }
            }
        }
        // bakctrack fill the sudoku
        fill(board, 0, 0, rows_, cols_, boxes_);
    }
    bool fill(vector<vector<char>>& board, int x, int y, vector<vector<int>>& rows_, vector<vector<int>>& cols_, vector<vector<int>>& boxes_){
        if(y == 9){
            return true;
        }
        int nx = (x + 1) % 9;
        int ny = nx == 0 ? (y + 1) : y;
        if(board[x][y] != '.'){
            return fill(board, nx, ny, rows_, cols_, boxes_);
        }
        for(int i = 1; i <= 9; ++i){
            int box_index = x / 3 * 3 + y / 3;
            if(!rows_[x][i] && !cols_[y][i] && !boxes_[box_index][i]){
                rows_[x][i] = 1;
                cols_[y][i] = 1;
                boxes_[box_index][i] = 1;
                board[x][y] = i +'0';
                if(fill(board, nx, ny, rows_, cols_, boxes_)) return true;
                rows_[x][i] = 0;
                cols_[y][i] = 0;
                boxes_[box_index][i] = 0;
                board[x][y] = '.';
            }
        }
        return false;
    }

};
// @lc code=end

