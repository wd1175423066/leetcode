/*
 * @lc app=leetcode.cn id=842 lang=cpp
 *
 * [842] 将数组拆分成斐波那契序列
 */

// @lc code=start
class Solution {
public:
    vector<int> splitIntoFibonacci(string num) {
        vector<int> ans;
        dfs(num, ans, 0);
        return ans;
    }
private:

    bool dfs(string s, vector<int>& ans, int pos){
        int l = s.length();
        if(pos == l){
           return ans.size() >= 3;
        }
        int max_len = s[pos] == '0' ? 1 : 10;
        long num = 0;
        for(int i = pos; i < min(pos + max_len, l); ++i){
            num = num * 10 + (s[i] - '0');
            if(num > INT_MAX){
                break;
            }
            if(ans.size() >= 2){
                long sum = ans.rbegin()[0];
                sum += ans.rbegin()[1];
                if(sum > num){
                    continue;
                }
                else if(sum < num){
                    break;
                }
            }
            ans.push_back(num);
            if(dfs(s, ans, i + 1)){
                return true;
            }
            ans.pop_back();
        }
        return false;
    }
};
// @lc code=end

