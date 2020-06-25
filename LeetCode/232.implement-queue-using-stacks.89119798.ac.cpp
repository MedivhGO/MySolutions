/*
 * [232] Implement Queue using Stacks
 *
 * https://leetcode.com/problems/implement-queue-using-stacks/description/
 *
 * algorithms
 * Easy (37.64%)
 * Total Accepted:    97.2K
 * Total Submissions: 258.4K
 * Testcase Example:  '["MyQueue","empty"]\n[[],[]]'
 *
 * 
 * Implement the following operations of a queue using stacks.
 * 
 * 
 * push(x) -- Push element x to the back of queue.
 * 
 * 
 * pop() -- Removes the element from in front of queue.
 * 
 * 
 * peek() -- Get the front element.
 * 
 * 
 * empty() -- Return whether the queue is empty.
 * 
 * 
 * Notes:
 * 
 * You must use only standard operations of a stack -- which means only push to
 * top, peek/pop from top, size, and is empty operations are valid.
 * Depending on your language, stack may not be supported natively. You may
 * simulate a stack by using a list or deque (double-ended queue), as long as
 * you use only standard operations of a stack.
 * You may assume that all operations are valid (for example, no pop or peek
 * operations will be called on an empty queue).
 * 
 * 
 */
class Queue {
public:
    // Push element x to the back of queue.
    stack<int> stk;
    void push(int x) {
            pushHelper(x);
    }
    void pushHelper(int x) {
        if(stk.size()==0) {
            stk.push(x);
            return;
        }
        int data;
        data = stk.top();
        stk.pop();
        pushHelper(x);
        stk.push(data);
        return ;
    }

    // Removes the element from in front of queue.
    void pop(void) {
        stk.pop();
    }

    // Get the front element.
    int peek(void) {
        return stk.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return stk.empty();
            
    }
};
