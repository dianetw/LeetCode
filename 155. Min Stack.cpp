/*
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 *
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 *
 * MinStack() initializes the stack object.
 * push(val) : Push element val onto stack.
 * pop() : Removes the element on top of the stack.
 * top() : Get the top element.
 * getMin() : Retrieve the minimum element in the stack.
 * 
 * Testcase Example:
 * Input:
 * ["MinStack","push","push","push","getMin","pop","top","getMin"]
 * [[],[-2],[0],[-3],[],[],[],[]]
 *
 * Ouput:
 * [null,null,null,null,-3,null,0,-2]
 *
 * Example:
 * 
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> Returns -3.
 * minStack.pop();
 * minStack.top();      --> Returns 0.
 * minStack.getMin();   --> Returns -2.
 */
// Runtime: 16 ms, faster than 97.40% of C++ online submissions for Min Stack.
// Memory Usage: 16.3 MB, less than 69.10% of C++ online submissions for Min Stack.
#include <stack>
class MinStack {
private:
    stack<int> currentStack;
    stack<int> minStack;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }

    void push(int val) {
        currentStack.push(val);
        if (minStack.empty() || minStack.top() >= val) {
            minStack.push(val);
        }
    }

    void pop() {
        if (currentStack.top() == minStack.top()) {
            minStack.pop();
        }
        currentStack.pop();
    }

    int top() {
        return !currentStack.empty() ? currentStack.top() : -1;
    }

    int getMin() {
        return !minStack.empty() ? minStack.top() : -1;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
