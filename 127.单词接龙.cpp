/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(!dict.count(endWord)){
            return 0;
        }
        //双向BFS
        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};
        int step = 0;
        int l = beginWord.length();

        while((!q1.empty()) && (!q2.empty())){
            ++step;
            if(q1.size() > q2.size()){
                swap(q1, q2);
            }
            unordered_set<string> q;
            for(string w : q1){
                for(int i = 0; i < l; ++i){
                    char ch = w[i];
                    for(int j = 'a'; j <= 'z'; ++j){
                        w[i] = j;
                        if(q2.count(w)){
                            return step + 1;
                        }
                        if(!dict.count(w)){
                            continue;
                        }
                        dict.erase(w);
                        q.insert(w);
                    }
                    w[i] = ch;
                }
            }
            swap(q1, q);
        }
        return 0;

        // 单向BFS
        // queue<string> q;
        // q.push(beginWord);
        // int l = beginWord.length();
        // int step = 0;

        // while(!q.empty()){
        //     ++step;
        //     for(int size = q.size(); size > 0; --size){
        //         string w = q.front();
        //         q.pop();
        //         for(int i = 0; i < l; ++i){
        //             char ch = w[i];
        //             for(int j = 'a'; j <= 'z'; ++j){
        //                 w[i] = j;
        //                 if(w == endWord){
        //                     return step + 1;
        //                 }
        //                 if(!dict.count(w)){
        //                     continue;
        //                 }
        //                 dict.erase(w);
        //                 q.push(w);
        //             }
        //             w[i] = ch;
        //         }
        //     } 
        // }
        return 0;
    }
};
// @lc code=end

