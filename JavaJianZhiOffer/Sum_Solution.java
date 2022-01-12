public class Sum_Solution {
    public static int Sum_Solution(int n) {
        int ans = n;
        if (n > 0) {
            ans+=Sum_Solution(n-1);
        }
        return ans;
    }

    public static void main(String[] args) {
        System.out.println(Sum_Solution(3));
    }
}