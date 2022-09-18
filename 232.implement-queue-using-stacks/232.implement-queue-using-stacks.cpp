/*
 * @lc app=leetcode id=232 lang=cpp
 *
 * [232] Implement Queue using Stacks
 */

// @lc code=start
/*
class MyQueue {
private:
    stack<int> in;
    stack<int> out;
public:
    MyQueue() {

    }
    
    void push(int x) {
        while (!out.empty()) {
            in.push(out.top());
            out.pop();
        }
        out.push(x);
        while (!in.empty()) {
            out.push(in.top());
            in.pop();
        }
    }
    
    int pop() {
        if (!out.empty()) {
            int t = out.top();
            out.pop();
            return t;
        }
        return -1;
    }
    
    int peek() {
        if (!out.empty()) return out.top();
        return -1;
    }
    
    bool empty() {
        return out.empty();
    }
};
*/
class MyQueue {
private:
    stack<int> in;
    stack<int> out;
public:
    MyQueue() {

    }
    
    void push(int x) {
        in.push(x);
    }
    
    int pop() {
        int t = peek();
        out.pop();
        return t;
    }
    
    int peek() {
        int t;
        if (!out.empty()) {
            t = out.top();
        } else {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
            t = out.top();
        }
        return t;
    }
    
    bool empty() {
        return out.empty() && in.empty() ? true : false;
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

