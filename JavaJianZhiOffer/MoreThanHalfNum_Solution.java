public class MoreThanHalfNum_Solution {
    public int MoreThanHalfNum_Solution(int [] array) {
    	
    	if (array == null) return 0;
    	int len = array.length;
    	int count = 1;
    	int cur = array[0];
    	for (int i = 1;i < len;i++) {
    		if (count == 0) {
    			cur = array[i];
    			count = 1;
    		} else if (cur == array[i]) {
    			count++;
    		} else {
    			count--;
    		}
    	}
    	 count = 0;
         for (int x : array) {
             if (x == cur) count++;
         }
         if (count > len/2)
     		return cur;
         else 
             return 0;   	
    }
    public static void main(String[] args) {
    	
    }
    
}