import java.util.ArrayList;
public class MinNumberInRotateArray {
    public int  MinNumberInRotateArray(int [] array) {
    	  if (array == null) return 0;
    	  if (array.length == 0) return 0;
    	  int left = 0,right = array.length-1;
    	  int mid = 0;
    	  while (array[left] >= array[right]) {
    		  if (right - left == 1) {
    			  mid = right;
    			  break;
    		  }
    		  mid = left + (right-left) / 2;
    		  if (array[left] == array[right] && array[left]!=0) {
    			  return getMin(array,left,right);
    		  } 
    		  else if (array[left]<=array[mid]){
    			  left = mid;
    		  }else {
    			  right = mid;
    		  }
    	  }
    	    
    	  return array[mid];
    	  
    }
    int getMin(int[] array,int left,int right) {
    	int ans = array[left];
    	for (int i = left+1;i < right;i++) {
    		if (array[i] < ans) {
    			ans = array[i];
    		}
    	}
    	return ans;
    }
    public static void main(String[] args) {
    	System.out.println("123");
    }
}