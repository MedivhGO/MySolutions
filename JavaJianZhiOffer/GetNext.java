public class GetNext {
    public class TreeLinkNode {
        int val;
        TreeLinkNode left = null;
        TreeLinkNode right = null;
        TreeLinkNode next = null;
        TreeLinkNode(int val) {
            this.val = val;
        }
    }
    public TreeLinkNode GetNext(TreeLinkNode pNode) {
        if (pNode == null) {
            return null;
        }
        if (pNode.right != null) {
            pNode = pNode.right;
            while (pNode.left!=null) {
                pNode = pNode.left;
            }
            return pNode;
        }
        while (pNode.next!=null) {
            TreeLinkNode t = pNode.next;
            if (t.left == pNode) return t;
            pNode = pNode.next;
        }
        return null;
    }
}