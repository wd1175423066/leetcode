/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string ip;
        dfs(s, ans, ip, 0);
        return ans;
    }
    void dfs(string s, vector<string>& ans, string ip, int k){
        int l = s.length();
        if(k == 4){
            if(l == 0){
                ans.push_back(ip);
            }
            return;
        }
        for(int i = 1; i <= min(3, s[0] == '0' ? 1 : l); ++i){
            string ss = s.substr(0, i);
            if(i == 3 && stoi(ss) > 255){
                return;
            }
            dfs(s.substr(i), ans, ip + (k == 0 ? "" : ".") + ss, k + 1);
        }
    }
};
// @lc code=end

