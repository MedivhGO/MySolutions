/*
 * [225] Implement Stack using Queues
 *
 * https://leetcode.com/problems/implement-stack-using-queues/description/
 *
 * algorithms
 * Easy (33.75%)
 * Total Accepted:    85.9K
 * Total Submissions: 254.4K
 * Testcase Example:  '["MyStack","empty"]\n[[],[]]'
 *
 * 
 * Implement the following operations of a stack using queues.
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
 * empty() -- Return whether the stack is empty.
 * 
 * 
 * Notes:
 * 
 * You must use only standard operations of a queue -- which means only push to
 * back, peek/pop from front, size, and is empty operations are valid.
 * Depending on your language, queue may not be supported natively. You may
 * simulate a queue by using a list or deque (double-ended queue), as long as
 * you use only standard operations of a queue.
 * You may assume that all operations are valid (for example, no pop or top
 * operations will be called on an empty stack).
 * 
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * all test cases.
 */
class Stack {
public:
    queue<int> qq;
    // Push element x onto stack.
    void push(int x) {
        qq.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int len = qq.size();
        for(int i=0;i<len-1;i++) {
            int data = qq.front();
            qq.pop();
            qq.push(data);
        }
        qq.pop();
        return ;
    }

    // Get the top element.
    int top() {
        return qq.back();
    }

    // Return whether the stack is empty.
    bool empty() {
        return qq.empty();
    }
};
