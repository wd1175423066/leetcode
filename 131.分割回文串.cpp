/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> subPal;
        dfs(s, ans, subPal);
        return ans;
    }
private:
    bool isPal(string s){
        int l = s.length();
        if(l == 0){
            return true;
        }
        int i = 0, j = l - 1;
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            ++i;
            --j;
        }
        return true;
    }
    void dfs(string s, vector<vector<string>>& ans, vector<string>& subPal){
        int l = s.length();
        if(l == 0){
            ans.push_back(subPal);
            return;
        }
        for(int i = 1; i <= l; ++i){
            string ss = s.substr(0, i);
            if(!isPal(ss)){
                continue;
            }
            subPal.push_back(ss);
            dfs(s.substr(i), ans, subPal);
            subPal.pop_back();
        }
    }

};
// @lc code=end

