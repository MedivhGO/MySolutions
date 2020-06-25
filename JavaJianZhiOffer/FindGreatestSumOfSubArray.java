
public class FindGreatestSumOfSubArray {
	 public int FindGreatestSumOfSubArray(int[] array) {
	       int len = array.length;
	       int ans = -9999;
	       int cursum = 0;
	       for (int i = 0;i < len;i++) {
	           cursum+=array[i];
	           if (cursum > ans)
	               ans = cursum;
	           if (cursum < 0)
	               cursum = 0;
	       }
	        return ans;
	  }
	 public static void main(String[] args) {
		
	 }
}
