//https://www.hackerrank.com/challenges/java-exception-handling/problem
//Write your code here
class MyCalculator  {
    int power(int a,int b) throws Exception {
        if ( a < 0 || b < 0 )
            throw new Exception(new String("n and p should be non-negative"));
        else
            return (int)Math.pow(a,b);
    }
}