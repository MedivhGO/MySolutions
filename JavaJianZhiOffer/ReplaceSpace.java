public class ReplaceSpace {
    public static String ReplaceSpace(StringBuffer str) {
    	if (str == null) return "";
    	//count space 
    	int count = 0;
    	int len = str.length();
    	for (int i = 0; i < len;i++) {
    		if (str.charAt(i) == ' ') 
    			count++;
    	}
    	for  (int i = 0;i<count*2;i++) {
    		str.append(" ");
    	}
    	int pend = len+2*count-1;
    	int oend = len - 1;
    	while (oend >= 0 && pend>oend  ) {
    		if (str.charAt(oend)!=' ') {
    			str.setCharAt(pend, str.charAt(oend));
    			pend--;
    		} else {
    			str.setCharAt(pend, '0');
    			pend--;
    			str.setCharAt(pend, '2');
    			pend--;
    			str.setCharAt(pend, '%');
    			pend--;
    		}
    		oend--;
    	}
    	return str.toString();
    }
    public static void main(String[] args) {
    	System.out.println(ReplaceSpace(new StringBuffer("We are happy")));
    }
}