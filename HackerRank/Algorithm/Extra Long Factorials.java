//https://www.hackerrank.com/challenges/extra-long-factorials/problem
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        BigDecimal cur = new BigDecimal(1);
        for (int i=1;i<=n;i++)
        {
            cur = cur.multiply(new BigDecimal(i));
        }
        System.out.println(cur);
    }
}
