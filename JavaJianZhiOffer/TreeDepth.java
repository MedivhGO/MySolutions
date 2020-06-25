
public class TreeDepth {
	
	public class TreeNode {
	    int val = 0;
	    TreeNode left = null;
	    TreeNode right = null;

	    public TreeNode(int val) {
	        this.val = val;

	    }

	}
	
	public int TreeDepth(TreeNode root) {
        return root==null ? 0 : 1+ Math.max(TreeDepth(root.left),TreeDepth(root.right));
    }
	public static void main()
	{
		
	}
}
