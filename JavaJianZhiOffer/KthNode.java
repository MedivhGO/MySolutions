public class KthNode {
	public class TreeNode {
	    int val = 0;
	    TreeNode left = null;
	    TreeNode right = null;

	    public TreeNode(int val) {
	        this.val = val;

	    }
	int count = 0;
    TreeNode KthNode(TreeNode pRoot, int k)
    {
       if (pRoot == null)
    	   return null;
       TreeNode t = KthNode(pRoot.left,k);
       if (t != null)
    	   return t;
       count++;
       if (count < k)
    	   return KthNode(pRoot.right,k);
       else if (count == k)
    	   return pRoot;
       
       return null;
        
        
    }
}
}