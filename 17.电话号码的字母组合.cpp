/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0){
            return ans;
        }
        vector<string> board={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string tmp;
        int pos = 0;
        backtracking(board, digits, pos, tmp, ans);
        return ans;
    }
    
    void backtracking(const vector<string> board, const string digits, int pos, string& tmp, vector<string>& ans){
        if(pos == digits.size()){
            ans.push_back(tmp);
            return;
        }
        for(int i = 0; i < board[digits[pos] - '0'].size(); ++i){
            tmp.push_back(board[digits[pos] - '0'][i]);
            backtracking(board, digits, pos + 1, tmp, ans);
            tmp.pop_back();
        }

    }
};
// @lc code=end

