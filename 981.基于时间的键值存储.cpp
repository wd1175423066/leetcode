/*
 * @lc app=leetcode.cn id=981 lang=cpp
 *
 * [981] 基于时间的键值存储
 */

// @lc code=start
class TimeMap {
    unordered_map<string, map<int, string>> um;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        um[key].emplace(timestamp, value);
        return;
    }
    
    string get(string key, int timestamp) {
        auto m = um.find(key);
        if(m == um.end()){
            return "";
        }
        auto it = m -> second.upper_bound(timestamp);
        if(it == begin(m -> second)){
            return "";
        }
        return prev(it) -> second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
// @lc code=end

