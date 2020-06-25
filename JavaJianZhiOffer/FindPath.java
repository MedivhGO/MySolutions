import java.util.ArrayList;


public class FindPath {
	public class TreeNode {
	    int val = 0;
	    TreeNode left = null;
	    TreeNode right = null;

	    public TreeNode(int val) {
	        this.val = val;

	    }

	}
	public ArrayList<ArrayList<Integer>> FindPath(TreeNode root,int target) {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> t = new ArrayList<Integer>();
        if (root == null) return ans;
        
        dfs(target,ans,t,root);
        
        return ans;
    }
    public void dfs(int target,ArrayList<ArrayList<Integer>> ans,ArrayList<Integer> tmp,TreeNode node) {
        tmp.add(node.val);
        if (node.left == null && node.right == null) {
            if (node.val == target) {
                ans.add(tmp);
            } 
            return;
        } 
            ArrayList<Integer> newTmp = new ArrayList<Integer>();
            newTmp.addAll(tmp);
            if (node.left != null)
            	dfs(target-node.val,ans,tmp,node.left);
            if (node.right != null)
            	dfs(target-node.val,ans,newTmp,node.right);
        
    }
    
    public static void main(String[] args) {
    	
    }
}