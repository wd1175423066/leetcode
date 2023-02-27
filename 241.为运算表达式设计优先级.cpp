/*
 * @lc app=leetcode.cn id=241 lang=cpp
 *
 * [241] 为运算表达式设计优先级
 */

// @lc code=start
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int l = expression.length();
        return dfs(expression);
    }
    vector<int> dfs(string expr){
        vector<int> ans;
        for(int i = 0; i < expr.length(); ++i){
            if(expr[i] >= '0' && expr[i] <= '9'){
                continue;
            }
            else{
                vector<int> left = dfs(expr.substr(0, i));
                vector<int> right = dfs(expr.substr(i + 1));
                for(auto lv : left){
                    for(auto rv : right){
                        int tmp = 0;
                        if(expr[i] == '+'){
                            tmp = lv + rv;
                        }
                        if(expr[i] == '-'){
                            tmp = lv - rv;
                        }
                        if(expr[i] == '*'){
                            tmp = lv * rv;
                        }
                        ans.push_back(tmp);
                    }
                }
            }
        }
        if(ans.empty()){
            ans.push_back(stoi(expr));
        }
        return ans;
    }
};
// @lc code=end

