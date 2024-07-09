class MyStack {
public:
    MyStack() {

    }
    
    void push(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }
    
    int pop() {
        int ret = q1.front();
        q1.pop();
        return ret;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
private:
    queue<int> q1; // 主队列
    queue<int> q2; // 辅助队列
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

 // push 的时间复杂度 O(n)

// 向辅助队列 q2 中 push 元素，然后将 q1 中的所有元素逐个 push 到 q2
// 这样最后插入的元素就到了队头。对于每次的 push 操作，经过代码 push 函数执行之后
// q1 中的所有元素都会按照插入顺序反转，也就是实现了栈的操作。
// 该问题可等价为，借用一个辅助队列，反转当前队列中的所有元素。