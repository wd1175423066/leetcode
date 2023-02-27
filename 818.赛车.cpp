/*
 * @lc app=leetcode.cn id=818 lang=cpp
 *
 * [818] 赛车
 */

// @lc code=start
class Solution {
public:
    int racecar(int target) {
        queue<pair<int, int>> q;
        q.push({0, 1});
        int step = 0;
        unordered_set<int> visited;
        visited.insert({0, 2});
        //visited.insert({0, -1});
        while(!q.empty()){
            ++step;
            int size = q.size();
            while(size--){
                auto p = q.front();
                q.pop();
                int pos = p.first;
                int speed = p.second;
                // A
                {
                    int pos1 = pos + speed;
                    int speed1 = speed * 2;
                    pair<int, int> p1{pos1, speed1};
                    // int key1 = (pos1 << 2) | (speed1 + 1);
                    if(pos1 == target){
                        return step;
                    }
                    // if(visited.count(key1)){
                    //     continue;
                    // }
                    if(pos1 > 0 && pos1 < 2 * target){
                        q.push(p1);
                    }
                    // visited.insert(key1);
                }
                // R
                {
                    int pos2 = pos;
                    int speed2 = speed > 0 ? -1 : 1;
                    pair<int, int> p2{pos2, speed2};
                    int key2 = (pos2 << 2) | (speed2 + 1);
                    if(!visited.count(key2)){
                        q.push(p2);
                        visited.insert(key2);
                    }
                }
            }
        }
        return -1;
    }
};
// @lc code=end

