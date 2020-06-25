//https://www.hackerrank.com/challenges/fibonacci-modified/problem
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        int t1 = scan.nextInt();
        int t2 = scan.nextInt();
        int n = scan.nextInt();

        BigDecimal cur =  new BigDecimal(t2) ;
        BigDecimal last = new BigDecimal(t1);

        for (int i=3;i<=n;i++) {
                BigDecimal t = last.add(cur.multiply(cur));
                last = cur;
                cur = t;

        }

        System.out.println(cur);
    }
}