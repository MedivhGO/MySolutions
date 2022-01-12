import java.util.Arrays;

public class ReConstructBinaryTree {
      public class TreeNode {
          int val;
          TreeNode left;
          TreeNode right;
          TreeNode(int x) { val = x; }
      };
   
    public TreeNode ReConstructBinaryTree(int [] pre,int [] in) {
         TreeNode root = ReConstructBinaryTree(pre,0,pre.length-1,in,0,in.length-1);
         return root;
    }

    public TreeNode ReConstructBinaryTree(int[] pre,int preb,int pree,int[] in,int inb,int ine) {
          if (preb > pree || inb > ine) {
            return null;
          }

          TreeNode root = new TreeNode(pre[preb]);

          for (int i = inb; i <= ine;i++) {
               if (in[i] == pre[preb]) {
                    root.left = ReConstructBinaryTree(pre,preb+1,preb+i-inb,in,inb,i-1);
                    root.right = ReConstructBinaryTree(pre,i-inb+preb+1,pree,in,i+1,ine);
               }
          }
          return root;
    }

    public static void main(String[] args) {
        System.out.println();
    }
}
