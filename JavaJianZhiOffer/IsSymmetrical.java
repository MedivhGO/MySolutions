
public class IsSymmetrical {
	public class TreeNode {
	    int val = 0;
	    TreeNode left = null;
	    TreeNode right = null;

	    public TreeNode(int val) {
	        this.val = val;

	    }
	}
    boolean IsSymmetrical(TreeNode pRoot)
    {
    	if (pRoot == null) return true;
    	if (pRoot.left == null && pRoot.right == null) return true;
    	if (pRoot.left == null || pRoot.left == null) return false;
    	return isSame(pRoot.left,pRoot.right);
        
    }
    public boolean isSame(TreeNode t1,TreeNode t2) {
    	if (t1 == null && t2 == null) return true;
    	if (t1 == null || t2 == null) return false;
    	if (t1.val == t2.val) {
    		return isSame(t1.left,t2.right) && isSame(t1.right,t2.left);	
    	} return false;
    		
    }
}