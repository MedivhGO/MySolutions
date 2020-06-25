public class NumberOf1 {
    public int NumberOf1(int n) { 
        
		int ans = 0;
        if (n == 0) return ans;
        ans++;
        int tmp = n & (n-1);
        while (tmp!=0) {
           ans++;
           tmp = tmp & (tmp-1);
        }
        return ans;
    }
    public static void main(String[] args) {
   
    }
}