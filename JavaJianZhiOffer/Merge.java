
public class Merge {
	
	public class ListNode {
	    int val;
	    ListNode next = null;

	    ListNode(int val) {
	        this.val = val;
	    }
	
    public ListNode Merge(ListNode list1,ListNode list2) {
        if (list1 == null && list2 == null) return null;
        if (list1 == null) return list2;
        if (list2 == null) return list1;

        ListNode ret = new ListNode(-1);
        ListNode ans = ret;
        ListNode p1 = list1;
        ListNode p2 = list2;
        while (p1 != null && p2 != null) {
        	if (p1.val<=p2.val) {
        		ret.next = p1;
        		p1 = p1.next;
        	} else {
        		ret.next = p2;
        		p2 = p2.next;
        		
        	}
        	ret = ret.next;
        }
        if (p1 == null) {
        	ret.next = p2;
        }
        if (p2 == null) {
        	ret.next = p1;
        }
        return ans.next;
    }
}
}