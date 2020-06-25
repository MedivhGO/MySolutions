public class ReverseList {
	public static  class ListNode {
	    int val;
	    ListNode next = null;

	    ListNode(int val) {
	        this.val = val;
	}
    public ListNode ReverseList(ListNode head) {
          if (head == null || head.next == null) return head;
            ListNode join = head.next;
        	ListNode newhead =  ReverseList(head.next);
            head.next = null;
            join.next = head;
            return newhead;
    }
    public static void   main(String[] args) {
    	
    }
}
}