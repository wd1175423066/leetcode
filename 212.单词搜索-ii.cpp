/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 */

// @lc code=start
class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        //unordered_set<string> unique_words(words.begin(), words.end());
        vector<string> ans;
        for(const string& word : words){
            if(exist(board, word)){
                ans.push_back(word);
            }
        }
        return ans;
    }
private:
    int m = 0;
    int n = 0;
    bool exist(vector<vector<char>>& board, string word){
        if(board.size() == 0){
            return false;
        }
        m = board.size();
        n = board[0].size();
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(search(board, word, 0, i, j)){
                    return true;
                }
            }
        }
        return false;
    }

    bool search(vector<vector<char>>& board, const string& word, int d, int x, int y){
        if(x < 0 || x == m || y < 0 || y == n || board[x][y] != word[d]){
            return false;
        }
        if(d == word.length() - 1){
            return true;
        }
        char cur = board[x][y];
        board[x][y] = '#';
        bool found = search(board, word, d + 1, x + 1, y) 
                    || search(board, word, d + 1, x - 1, y)
                    || search(board, word, d + 1, x, y + 1)
                    || search(board, word, d + 1, x, y - 1);
        board[x][y] = cur;

        return found;
    }

};
// @lc code=end

