//https://www.hackerrank.com/challenges/phone-book/problem
//Complete this code or write your own from scratch
import java.util.*;
import java.io.*;

class Solution{
   public static void main(String []argh)
   {
      HashMap<String,Integer> mapping = new HashMap<>();
      Scanner in = new Scanner(System.in);
      int n=in.nextInt();
      in.nextLine();
      for(int i=0;i<n;i++)
      {
         String name=in.nextLine();
         int phone=in.nextInt();
         in.nextLine();
         mapping.put(name,phone);
      }
      while(in.hasNext())
      {
         String s=in.nextLine();
          if(!mapping.containsKey(s))
              System.out.println("Not found");
          else {
              System.out.println(s+"="+mapping.get(s));
          }
      }
   }
}

