import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;



public class PrintFromTopToBottom {
	public class TreeNode {
	    int val = 0;
	    TreeNode left = null;
	    TreeNode right = null;

	    public TreeNode(int val) {
	        this.val = val;

	    }
	}
    public ArrayList<Integer> PrintFromTopToBottom(TreeNode root) {
        ArrayList<Integer> al = new ArrayList<Integer>();
        if (root == null) return al;
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.offer(root);
        while (q.isEmpty()!=true) {
        	TreeNode t = q.poll();
        	al.add(t.val);
        	if (t.left!=null)
        		q.offer(t.left);
        	if (t.right!=null)
        		q.offer(t.right);
        }
        return al;
     
    }
}