import java.util.ArrayList;
import java.util.Collections;
public class Permutation {
    public ArrayList<String> Permutation(String str) {
       ArrayList<String> ans = new ArrayList<>();
       if (str !=null || str.length() != 0) {
    	   PermutationHelper(str.toCharArray(),0,ans);
    	   Collections.sort(ans);
    	   return ans;
    	   		
       } else {
    	   	   return ans;
       }
    	   
    }
    public void PermutationHelper(char[] cs,int i,ArrayList list) {
    	   if (i == cs.length-1) {
    		   String val = String.valueOf(cs);
    		   if (!list.contains(val))
    			   list.add(val);
    	   } else {
    		   for (int j = i; j < cs.length;j++) {
    			   swap(cs,i,j);
    			   PermutationHelper(cs,i+1,list);
    			   swap(cs,i,j);
    		   }
    	   }
    }
    private void swap(char[] strs,int i,int j) {
    		char temp = 0;
    		temp = strs[i];
    		strs[i] = strs[j];
    		strs[j] = temp;
    }
}