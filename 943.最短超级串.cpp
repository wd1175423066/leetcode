/*
 * @lc app=leetcode.cn id=943 lang=cpp
 *
 * [943] 最短超级串
 */

// @lc code=start
class Solution {
public:
    string shortestSuperstring(vector<string>& words) {
        const int n = words.size();
        overlap = vector<vector<int>>(n, vector<int>(n));
        order = vector<int>(n);
        // caculate overlap char
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(i == j){
                    continue;
                }
                int k = min(words[i].size(), words[j].size());
                for(; k > 0; --k){
                    if(words[i].substr(words[i].size() - k) == words[j].substr(0, k)){
                        overlap[i][j] = k;
                        break;
                    }
                }
            }
        }
        // dfs for order
        dfs(words, 0, 0, 0);

        // generate final string
        return genString(words, n);
    }
private:
    int min_length = INT_MAX;
    vector<vector<int>> overlap;
    vector<int> order;
    vector<int> best_order;

    void dfs(vector<string>& words, int pos, int curLen, int used){
        if(curLen >= min_length){
            return;
        }
        if(pos == words.size()){
            best_order = order;
            min_length = curLen;
            return;
        }
        for(int i = 0; i < words.size(); ++i){
            if(used & (1 << i)){
                continue;
            }
            order[pos] =  i;
            int nextLen = (pos == 0) ? words[i].size() : curLen + words[i].size() - overlap[order[pos - 1]][i];
            dfs(words, pos + 1, nextLen, used | (1 << i));
        }
    }

    string genString(const vector<string>& words, int n){
        string ans = words[best_order[0]];
        for(int k = 1; k < n; ++k){
            int i = best_order[k - 1];
            int j = best_order[k];
            ans += words[j].substr(overlap[i][j]);
        }
        return ans;
    }
};
// @lc code=end

