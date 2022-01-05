public class Clone {
	public class RandomListNode {
	    int label;
	    RandomListNode next = null;
	    RandomListNode random = null;

	    RandomListNode(int label) {
	        this.label = label;
	    }
	}
    public RandomListNode Clone(RandomListNode pHead)
    {
        if (pHead == null ) return null;
        RandomListNode cur = pHead;
        while (cur!=null) {
            RandomListNode cp = new RandomListNode(cur.label);
            cp.next = cur.next;
            cur.next =cp;
            cur = cur.next.next;
        }
        RandomListNode newHead = pHead.next;
        cur = pHead;
        while (cur!=null) {
            RandomListNode t = cur.random;
            if (t!=null) {
                cur.next.random = t.next;
            }
            cur = cur.next.next;
        }
        cur = pHead;
        while (cur!=null) {
          RandomListNode t = cur.next;
          cur.next = t.next;
          if (t.next!=null) 
              t.next = t.next.next;
          cur = cur.next;
        }
        return newHead;
        
    }
}