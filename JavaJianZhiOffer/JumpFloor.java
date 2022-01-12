public class JumpFloor {
    public static int JumpFloor(int target) {
        //dp
        int n1 = 1,n2=2;
        if (target == 0) return 0;
        if (target == 1) return n1;
        if (target == 2) return n2;
        for (int i = 3;i <=target;i++) {
            int t = n2;
            n2 = n1+n2;
            n1 = t;
        }
        return n2;
    }

    public static void main(String[] args) {
        System.out.println(JumpFloor(4));
    }
}