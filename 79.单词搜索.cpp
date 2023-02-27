/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int count = 0;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> isVisited(board.size(), vector<bool>(board[0].size(), false));
        if(n == 0) return false; 
        bool find = false;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                backtracking(board, isVisited, count, word, i, j, find);
            }
        }
        return find;
    }

    void backtracking(const vector<vector<char>>& board, vector<vector<bool>>& isVisited, const int count, const string& word, const int i, const int j, bool& find){
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size()){
            return;
        }
        if(isVisited[i][j] || word[count] != board[i][j] || find){
            return;
        }
        if(word.size() - 1 == count){
            find = true;
            return;
        }
        isVisited[i][j] = true;
        backtracking(board, isVisited, count + 1, word, i, j + 1, find);
        backtracking(board, isVisited, count + 1, word, i, j - 1, find);
        backtracking(board, isVisited, count + 1, word, i + 1, j, find);
        backtracking(board, isVisited, count + 1, word, i - 1, j, find);
        isVisited[i][j] = false;
    }
};
// @lc code=end

