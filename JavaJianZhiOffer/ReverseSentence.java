import java.util.ArrayList;
import java.util.Collections;

public class ReverseSentence {
    public static String ReverseSentence(String str) {
    	  if (str == null || str.length() == 0 || str.length()==1) return str;
         // if (str.trim().equals("")) return str;

        String[] allstring = str.split(" ");
        
        System.out.println(allstring.length);
        if (allstring.length==0) return str;
        ArrayList<StringBuffer> al = new ArrayList<>();
        int i = 0;
        for (String x : allstring) {
        	 al.add( new StringBuffer(x));
        	
        	al.get(i).reverse();
        	i++;
        }
        StringBuffer ans = new StringBuffer();
        for (StringBuffer x : al) {
        	  ans.append(x+" ");
        }
        ans.reverse();
        return ans.toString().trim();

    }
    public static void main(String[] args) {
    	String s = "     ";
    	System.out.println(ReverseSentence(s));
    }
}