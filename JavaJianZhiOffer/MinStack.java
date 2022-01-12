import java.util.Stack;

public class MinStack {
    private Stack<Integer> stk1 = new Stack<Integer>();
    private Stack<Integer> minstk = new Stack<Integer>();
    public void push(int node) {
        stk1.push(node);
        if (minstk.isEmpty() == true || minstk.peek()>node) {
            minstk.push(node);
        }
    }

    public void pop() {
        if (stk1.isEmpty() == false) {
            int t = stk1.pop();
            if (minstk.isEmpty() == false && minstk.peek() == t) {
                minstk.pop();
            }
        }
    }

    public int top() {
        return stk1.peek();
    }

    public int min() {
        return minstk.peek();
    }

    public static void main(String[] args) {}
}