import java.util.ArrayList;

public class IsPopOrder {
    public boolean IsPopOrder(int [] pushA,int [] popA) {
        if (pushA.length == 0)
            return false;
        ArrayList<Integer> al = new ArrayList<>();
        for (int i = 0,j = 0; i < pushA.length;) {
            al.add(pushA[i++]);
            while (j < popA.length && al.get(al.size()-1)==popA[j]) {
                al.remove(al.size()-1);
                j++;
            }
        }
        return al.isEmpty();
    }
}