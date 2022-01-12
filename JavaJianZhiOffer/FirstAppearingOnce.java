import java.util.*;

public class FirstAppearingOnce {
    //Insert one char from stringstream
    HashMap<Character,Integer> hm = new HashMap<>();
    ArrayList<Character> cla = new ArrayList<>();
    public void Insert(char ch) {
        if (hm.containsKey(ch)) {
            hm.put(ch,hm.get(ch)+1);
        } else {
            hm.put(ch,1);
        }
        cla.add(ch);
        
    }
  //return the first appearence once char in current stringstream
    public char FirstAppearingOnce() {
        char ans = '#';
        for (char t : cla) {
            if (hm.get(t) == 1) {
                ans = t;
                break;
            }
        }
        return ans;
    }
}