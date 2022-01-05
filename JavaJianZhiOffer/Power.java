public class Power {
    public static double Power(double base, int exponent) {
    	  if (exponent == 0) return 1;
          if (exponent == 1) return base;
          int binary = 0;
          int flag = 0;
          if (exponent < 0) flag = 0;
          else flag = 1;
          exponent = Math.abs(exponent);
          if (exponent%2 == 0) {
              binary = 1;
          } else {
              binary = 0;
          }
          double ans = Power(base,exponent/2);
          if (binary == 1) ans *=ans;
          else ans = ans*ans*base;
          if (flag == 1) return ans;
          else return 1/ans;
    }
    public static void main(String[] args) {
    	System.out.println(Power(2,-3));
    }
    
}