import java.util.ArrayList;
import java.util.Stack;
public class PrintListFromTailToHead {
    public class ListNode {
        int val;
        ListNode next = null;
        ListNode(int val) {
            this.val = val;
        }
    }

    public ArrayList<Integer> printListFromTailToHead(ListNode listNode) {
        ArrayList<Integer> al = new ArrayList<Integer>();
        if (listNode == null) return  al;
        Stack<Integer> stk = new Stack<Integer>();
        ListNode p = listNode;
        while(p!=null) {
            stk.push(p.val);
            p = p.next;
        }
        while (!stk.empty()) {
            al.add(stk.pop());
        }
        return al;
    }
}