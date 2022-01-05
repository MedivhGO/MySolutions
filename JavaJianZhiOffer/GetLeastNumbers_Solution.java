import java.util.ArrayList;
import java.util.Comparator;
import java.util.PriorityQueue;

public class GetLeastNumbers_Solution {
	 public ArrayList<Integer> GetLeastNumbers_Solution(int [] input, int k) {
	        ArrayList<Integer> result = new ArrayList<Integer>();
	        int len = input.length;
	        if (k > len || k == 0) {
	        	return result;
	        }
	        PriorityQueue<Integer> maxHeap = new PriorityQueue<Integer>(k,new Comparator<Integer>() {
	        	public int compare(Integer o1, Integer o2) {
	                return o2.compareTo(o1);
	            }
	        });
	        
	        for(int i = 0; i < len;i++) {
	        	if (maxHeap.size() !=k) {
	        		maxHeap.offer(input[i]);
	        	} else if (maxHeap.peek() > input[i]) {
	        		Integer temp = maxHeap.poll();
	        		temp =null;
	        		maxHeap.offer(input[i]);
	        	}
	        }
	        for (Integer integer : maxHeap) {
	        	result.add(integer);
	        }
	        
	        return result;
	  }
}
