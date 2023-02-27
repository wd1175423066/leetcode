/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

// @lc code=start
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        // 统计 非法左右括号的数量
        int l = 0;
        int r = 0;

        for(const char ch : s){
            l += (ch == '(');
            if(l == 0){
                r += (ch == ')');
            }
            else{
                l -= (ch == ')');
            }
        }
        vector<string> ans;
        dfs(s, 0, l, r, ans);
        return ans;
    }
private:
    // 判断括号是否合法
    bool isValid(const string& s){
        int count = 0; //初值
        for(const char ch : s){
            if(ch == '(') ++count;
            if(ch == ')') --count;
            if(count < 0) return false;
        }
        return count == 0;
    }

    // dfs
    void dfs(const string& s, int pos, int l, int r, vector<string>& ans){
        if(l == 0 && r == 0){
            if(isValid(s)) ans.push_back(s);
            return;
        }

        for(int i = pos; i < s.size(); ++i){
            if(i != pos && s[i] == s[i - 1]) continue;
            if(s[i] == '(' || s[i] == ')'){
                string cur = s;
                cur.erase(i, 1);
                if(r > 0 && s[i] == ')'){
                    dfs(cur, i, l, r - 1, ans);
                }
                else if(l > 0 && s[i] == '('){
                    dfs(cur, i, l - 1, r, ans);
                }
            }
        }
    }
};
// @lc code=end

