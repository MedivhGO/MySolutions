//https://www.hackerrank.com/challenges/java-negative-subarray/problem
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        int count = 0;

        Scanner scan = new Scanner(System.in);
        int len = scan.nextInt();
        int[] arr = new int[len];
        for ( int i = 0 ; i < len ; i++) {
            arr[i] = scan.nextInt();
        }
        for ( int i = 0 ;  i< len ; i++) {
            int sum = 0;
            for(int j=i ; j < len ; j++) {
                sum+=arr[j];
                if(sum < 0)
                      count++;
            }

        }
        System.out.println(count);
    }
}