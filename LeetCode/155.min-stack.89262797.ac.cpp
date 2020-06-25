/*
 * [155] Min Stack
 *
 * https://leetcode.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (30.15%)
 * Total Accepted:    163.7K
 * Total Submissions: 542.9K
 * Testcase Example:  '["MinStack","push","push","push","getMin","pop","top","getMin"]\n[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 
 * Design a stack that supports push, pop, top, and retrieving the minimum
 * element in constant time.
 * 
 * 
 * push(x) -- Push element x onto stack.
 * 
 * 
 * pop() -- Removes the element on top of the stack.
 * 
 * 
 * top() -- Get the top element.
 * 
 * 
 * getMin() -- Retrieve the minimum element in the stack.
 * 
 * 
 * 
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
 * 
 * 
 */
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> stk;
    stack<int> stk1;//最小值的栈，栈顶一直为最小值，不是所有push的值都会入栈
    int min;
    MinStack() {
        min = INT_MAX;
    }
    
    void push(int x) {
        
        stk.push(x);
        if( x<=min) {
            stk1.push(x);
            min=x;
        }
    }
    
    void pop() {
        if(stk1.top() == stk.top()) {
            stk1.pop();
        }
            stk.pop();
            min = getMin();

       
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        if(stk1.empty())
            return INT_MAX;
        return stk1.top();
    }
};
