//https://www.hackerrank.com/challenges/java-end-of-file/problem
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner scan = new Scanner(System.in);
        int n=0;
        while(scan.hasNextLine()) {
            n++;
            String s = scan.nextLine();
            System.out.println(n+" " + s);
        }
    }
}