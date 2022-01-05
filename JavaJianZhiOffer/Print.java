import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

public class Print {
	
	public class TreeNode {
	    int val = 0;
	    TreeNode left = null;
	    TreeNode right = null;

	    public TreeNode(int val) {
	        this.val = val;

	    }

	}
    ArrayList<ArrayList<Integer> > Print(TreeNode pRoot) {
    	ArrayList<ArrayList<Integer>>  al = new ArrayList<ArrayList<Integer>>();
    	if (pRoot == null) return al;
    	Queue<TreeNode> q = new LinkedList<>();
    	q.offer(pRoot);
    	while (q.isEmpty() == false) {
    	   ArrayList<Integer> ai = new ArrayList<Integer>();
    	   int qlen = q.size();
    	   while (qlen!=0) {
    		   TreeNode t = q.poll();
    		   ai.add(t.val);
    		   qlen--;
    		   if (t.left != null)
    			   q.offer(t.left);
    		   if (t.right!=null)
    			   q.offer(t.right);
    	   }
    	   al.add(ai);
    	   
    	}
    	return al;
    }
    public static void main(String[] args) {
    	
    }
    
}