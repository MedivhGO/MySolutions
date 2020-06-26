//https://www.hackerrank.com/challenges/java-list/problem
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n  = scan.nextInt();
        List ls  = new ArrayList();
        for ( int i = 0 ; i < n ; i++) {
            ls.add(scan.nextInt());
        }
        int nq = scan.nextInt();
        for ( int i = 0 ; i < nq*2 ; i++) {
            String s = scan.nextLine();

            if (s.equals("Insert")) {
                int x = scan.nextInt();
                int y = scan.nextInt();
                ls.add(x,y);
            }
            else if (s.equals("Delete")) {

                int r = scan.nextInt();

                ls.remove(r);
            }
        }

       for ( int i = 0; i< ls.size() ; i++) {
           System.out.print(ls.get(i)+" ");
       }
    }
}
