public class Fibonacci {
    public static int Fibonacci(int n) {
    			
    	//dp
       int last = 1,cur = 1;
       if (n == 0) return 0;
       if (n == 1) return last;
       if (n == 2) return cur;
       for (int i = 3 ; i<=n;i++) {
    	   int t = cur; //cur �ᱻ�ı����Լ�¼
    	   cur = last + cur;
    	   last = t;
       }
       return cur;
       
    }
    public static void main(String[] args) {
    	System.out.println(Fibonacci(3));
    }
    
}