/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
private:
    class MyQueue{
        public:
            deque<int> dq;
            
            void pop(int value) {
                if(!dq.empty() && value == dq.front()) {
                    dq.pop_front();
                }
            } 
            void push(int value) {
                while(!dq.empty() && value > dq.back()) {
                    dq.pop_back();
                }
                dq.push_back(value);
            }
            int front() {
                return dq.front();
            }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que;
        vector<int> res;
        for(int i = 0; i < k; ++i) {
            que.push(nums[i]);
        }
        res.push_back(que.front());
        for(int i = k; i < nums.size(); ++i) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            res.push_back(que.front());
        }
        return res;
    }
};
// @lc code=end

