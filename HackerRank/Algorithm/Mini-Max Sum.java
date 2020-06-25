//https://www.hackerrank.com/challenges/mini-max-sum/problem

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int[] arr = new int[5];
        for(int arr_i=0; arr_i < 5; arr_i++){
            arr[arr_i] = in.nextInt();
        }
        BigDecimal bd = new BigDecimal(0);
        for (int x : arr) {
            bd = bd.add(new BigDecimal(x));
        }

        BigDecimal minarr = bd;
        BigDecimal maxarr = new BigDecimal(arr[0]);
        for (int x :arr) {
            BigDecimal tmp = bd.subtract(new BigDecimal(x));

            if (tmp.compareTo(maxarr)> 0)
                maxarr = tmp;
            if (tmp.compareTo(minarr)<0 )
                minarr = tmp;

        }
        System.out.println(minarr+" "+maxarr);
    }
}
