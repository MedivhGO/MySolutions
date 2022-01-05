

public class FindFirstCommonNode {
	public class ListNode {
	    int val;
	    ListNode next = null;

	    ListNode(int val) {
	        this.val = val;
	    }
	}
    public ListNode FindFirstCommonNode(ListNode pHead1, ListNode pHead2) {
 			if (pHead1==null || pHead2 == null) return null;
        	int len1 = 0;
            ListNode p = pHead1;
            while (p!=null) {
                len1++;
                p = p.next;
            }
            int len2 = 0;
            p = pHead2;
            while (p!=null) {
                len2++;
                p = p.next;
            }
            ListNode p1 = null;
            if (len1 >= len2){
               p = pHead1; 
               p1 = pHead2;
            } else {
                p = pHead2;
                p1 = pHead1;
            }
            int pre = Math.abs(len1-len2);
            while (pre!=0) {
                p = p.next;
                pre--;
            }
            while (p!=p1) {
                p = p.next;
                p1 = p1.next;
            }
            return p;
    }
    public static void  main(String[] args) {
    	
    }
}