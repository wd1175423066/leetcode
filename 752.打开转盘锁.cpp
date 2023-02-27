/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        const string start = "0000";
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if(dead.count(start)){
            return -1;
        }
        if(start == target){
            return 0;
        }

        queue<string> q1;
        unordered_set<string> v1{start};
        queue<string> q2;
        unordered_set<string> v2{target};
        q1.push(start);
        q2.push(target);
        int step = 0;

        while(!q1.empty() && !q2.empty()){
            ++step;
            for(int size = q1.size(); size > 0; --size){
                string w = q1.front();
                q1.pop();
                for(int i = 0; i < 4; ++i){
                    const char ch = w[i];
                    for(int j = -1; j <= 1; j+=2){
                        w[i] = (ch - '0' + j + 10) % 10 + '0';
                        if(v2.count(w)){
                            return step;
                        }
                        if(dead.count(w) || v1.count(w)){
                            continue;
                        }
                        q1.push(w);
                        v1.insert(w);
                    }
                    w[i] = ch;
                }
            }
            swap(q1, q2);
            swap(v1, v2);
        }
        return -1;
    }
};
// @lc code=end

