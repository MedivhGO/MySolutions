//https://www.hackerrank.com/challenges/
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int a0 = in.nextInt();
        int a1 = in.nextInt();
        int a2 = in.nextInt();
        int b0 = in.nextInt();
        int b1 = in.nextInt();
        int b2 = in.nextInt();

        int resa=0,resb=0;

        if(a0>b0) {
            resa++;
        }
        else if(a0<b0){
            resb++;
        }
         if(a1>b1) {
            resa++;
        }
        else if(a1<b1){
            resb++;
        }
         if(a2>b2) {
            resa++;
        }
        else if(a2<b2){
            resb++;
        }
        System.out.println(resa+" "+resb);
    }
}
