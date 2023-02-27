/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)) return {};
        dict.erase(beginWord);

        unordered_map<string, int> steps{{beginWord, 1}};
        unordered_map<string, vector<string>> parents;
        queue<string> q;
        q.push(beginWord);

        vector<vector<string>> ans;

        const int l = beginWord.length();
        int step = 0;
        bool found = false;

        // generate graph
        while(!q.empty() && !found){
            ++step;
            for(int size = q.size(); size > 0; --size){
                const string p = q.front();
                q.pop();
                string w = p;
                for(int i = 0; i < l; ++i){
                    const char ch = w[i];
                    for(int j = 'a'; j <= 'z'; ++j){
                        w[i] = j;
                        if(!dict.count(w)){
                            if(steps.count(w) && step < steps[w]){
                                parents[w].push_back(p);
                            }
                            continue;
                        }
                        dict.erase(w);
                        q.push(w);
                        steps[w] = step + 1;
                        parents[w].push_back(p);
                        if(w == endWord){
                            found = true;
                        }
                    }
                    w[i] = ch;
                }
            }
        }
        
        // search smallest path using dfs
        if(found){
            vector<string> curr{endWord};
            getPaths(endWord, beginWord, parents, curr, ans);
        }
        return ans;
    } 

private:
    void getPaths(const string& word, const string& beginWord, const unordered_map<string, vector<string>>& parents, vector<string>& curr, vector<vector<string>>& ans){
        if(word == beginWord){
            ans.push_back(vector<string>(curr.rbegin(), curr.rend()));
            return;
        }
        for(const string& p : parents.at(word)){
            curr.push_back(p);
            getPaths(p, beginWord, parents, curr, ans);
            curr.pop_back();
        }
    }
};
// @lc code=end

