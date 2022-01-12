public class FindKthToTail {
    
    public class ListNode {
        int val;
        ListNode next = null;

        ListNode(int val) {
            this.val = val;
        }
    }

     public ListNode FindKthToTail(ListNode head,int k) {
             if (head == null || k <=0 ) return null;
             ListNode pre = head;
             int len = 0;
             while (pre!=null) {
                 len++;
                 pre = pre.next;
             }
             if (len<k) return null;
             pre = head;
             while (k!=0) {
                 pre = pre.next;
                 k--;
             }
             ListNode later = head;
             while (pre!=null) {
                 later = later.next;
                 pre = pre.next;
             }
             return later;
     }

     public static void main(String[] args) {
     }
     
}
