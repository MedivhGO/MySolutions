import java.util.ArrayList;
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

import org.w3c.dom.Node;

public class PrintZ {
    public class TreeNode {
        int val = 0;
        TreeNode left = null;
        TreeNode right = null;
        public TreeNode(int val) {
            this.val = val;
        }
    }

    ArrayList<ArrayList<Integer> > PrintZ(TreeNode pRoot) {
        ArrayList<ArrayList<Integer>>  al = new ArrayList<ArrayList<Integer>>();
        if (pRoot == null) return al;
        Queue<TreeNode> q = new LinkedList<>();
        q.offer(pRoot);
        int count = 0;
        while (q.isEmpty() == false) {
            count++;
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
           if ((count & 1) == 0)
               Collections.reverse(ai);
           al.add(ai);
        }
        return al;
    }
    ArrayList<ArrayList<Integer> > PrintZ1(TreeNode pRoot){
        ArrayList<ArrayList<Integer>> al = new ArrayList<ArrayList<Integer>>();
        if (pRoot == null) return al;
        ArrayList<Integer> list = new ArrayList<>();
        LinkedList<TreeNode> queue = new LinkedList<>();
        queue.addLast(null); //²ã·Ö¸ô·û
        queue.addLast(pRoot);
        boolean leftToRight = true;
        while (queue.size() != 1) {
            TreeNode node = queue.removeFirst();
            if (node == null) {
                Iterator<TreeNode> iter = null;
                if (leftToRight) {
                    iter = queue.iterator();        
                } else {
                    iter = queue.descendingIterator();
                }
                leftToRight = !leftToRight;
                while (iter.hasNext()) {
                    TreeNode temp = (TreeNode)iter.next();
                    list.add(temp.val);
                }
                al.add(new ArrayList<Integer>(list));
                list.clear();
                queue.add(null);
                continue;
            }
            if (node.left != null) {
                queue.addLast(node.left);
            }
            if (node.right != null) {
                queue.addLast(node.right);
            }
        }
        return al;
    }
    public static void main(String[] args) {
    }
}