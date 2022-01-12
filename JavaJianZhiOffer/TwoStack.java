import java.util.Stack;

public class TwoStack {
    Stack<Integer> stack1 = new Stack<Integer>();
    Stack<Integer> stack2 = new Stack<Integer>();
    private boolean flag = true;
    public void push(int node) {
       if (stack1.isEmpty()!=true) {
                 stack1.push(node);
                 flag = true;
       }
       else { 
                 stack2.push(node);
                 flag = false;
       }
    } 
    public int pop() { // 将非空的栈中元素逐个出栈到空栈，然后出栈其栈顶元素
            if (flag == true) {
                while (stack1.isEmpty() == false) {
                    stack2.push(stack1.pop());
                }
                return stack2.pop();
            } else {
                while (stack2.isEmpty() == false) {
                    stack1.push(stack2.pop());
                }
                return stack1.pop();
            }
    }
}