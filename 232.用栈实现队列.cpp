/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue {
    stack<int> iStack;
    stack<int> oStack;
public:
    MyQueue() {

    }
    
    void push(int x) {
        iStack.push(x);
    }
    
    int pop() {
        if(oStack.empty()) {
            while(!iStack.empty()) {
                oStack.push(iStack.top());
                iStack.pop();
            }
        }
        int res = oStack.top();
        oStack.pop();
        return res;
    }
    
    int peek() {
        int res = this -> pop();
        oStack.push(res);
        return res;
    }
    
    bool empty() {
        return oStack.empty() && iStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

