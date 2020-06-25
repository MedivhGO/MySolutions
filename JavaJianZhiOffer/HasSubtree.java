public class HasSubtree {
	
	
	public class TreeNode {
	    int val = 0;
	    TreeNode left = null;
	    TreeNode right = null;

	    public TreeNode(int val) {
	        this.val = val;

	    }

	}
    public boolean HasSubtree(TreeNode root1,TreeNode root2) {
        if (root1 == null || root2 == null) return false;
        
        return isSubtree(root1,root2) || isSubtree(root1.left,root2) || isSubtree(root1.right,root2);
        
    }
    public boolean isSubtree(TreeNode t1,TreeNode t2) {
    
    	if (t2 == null) return true;
    	if (t1 == null) return false;
    	if (t1.val == t2.val) {
    		return isSubtree(t1.left,t2.left) && isSubtree(t1.right,t2.right);
    	} return false;
    }
}