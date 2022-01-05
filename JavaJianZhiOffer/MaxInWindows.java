import java.util.ArrayDeque;
import java.util.ArrayList;

public class MaxInWindows {
    public ArrayList<Integer> MaxInWindows(int [] num, int size)
    {	
    		ArrayList<Integer> ans = new ArrayList<Integer>();
    		if (size == 0) return ans;
    		int begin;
    		ArrayDeque<Integer> q = new ArrayDeque<>();
    		for (int i = 0; i < num.length;i++) {
    			begin = i - size + 1;
    			if (q.isEmpty())
    				q.add(i);
    			else if (begin>q.peekFirst())
    				q.pollFirst();
    			
    			while ((!q.isEmpty()) && num[q.peekLast()] <= num[i])
    				q.pollLast();
    			q.add(i);
    			if (begin>=0)
    				ans.add(num[q.peekFirst()]);
    		}
    		return ans;
    }
}