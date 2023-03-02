/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        vector<string> names;
        auto split = [&](){
            string cur;
            for(char ch : path) {
                if(ch == '/') {
                    if(cur.size() != 0) names.push_back(cur);
                    cur.clear();
                }
                else {
                    cur += ch;
                }
            }
            if(cur.size() != 0) names.push_back(move(cur));
        };
        split();
        vector<string> stk;
        for(const string& name : names) {
            if(name == "..") {
                if(stk.size() > 0) stk.pop_back();
                else continue;
            }
            else if(name == ".") continue;
            else stk.push_back(name);
        }

        string res = "/";
        for(const string& s : stk) {
            res += s + "/";
        }
        if(res.size() > 1) res.pop_back();
        return res;


    }
};
// @lc code=end

