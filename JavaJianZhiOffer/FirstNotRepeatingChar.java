import java.util.Hashtable;

class FirstNotRepeatingChar {
	public int FirstNotRepeatingChar(String str) {
		if (str == null) return -1;
        Hashtable<Character,Integer> ht = new Hashtable<>();
        int len = str.length();
        for (int i = 0; i < len;i++) {
        	Character t = str.charAt(i);
        	if (ht.containsKey(t)) {
        		ht.put(t, 1);
        	} else {
        		int count = ht.get(t);
        		count++;
        		ht.put(t, count);
        	}
        }
        for (int i = 0; i < len;i++) {
        	Character t = str.charAt(i);
        	int count = ht.get(t);
        	if (count == 1)
        		return i;
        }
        return -1;
        
    }
	public static void main(String[] args) {
		
		
	}
};