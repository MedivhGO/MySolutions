//https://www.hackerrank.com/challenges/java-arraylist/problem
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int line = scan.nextInt();
        ArrayList<ArrayList<Integer>> arr = new ArrayList<>();

        for ( int i=0;i < line ; i++ ) {
            int col = scan.nextInt();
             ArrayList  tarr = new ArrayList();
            for( int j = 0; j < col ; j++ ) {
                int t = scan.nextInt();
                tarr.add(t);
            }
            arr.add(tarr);
        }
        int qn = scan.nextInt();

        for ( int i = 0; i < qn ; i++ ) {
            int x = scan.nextInt();
            int y = scan.nextInt();
            try{
                int res = (arr.get(x-1)).get(y-1);
                System.out.println(res);
            } catch (Exception e) {
                System.out.println("ERROR!");
            }
        }

        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
    }
}