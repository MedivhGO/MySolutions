//https://www.hackerrank.com/challenges/java-int-to-string/problem
   //Write your code here

   StringBuffer sbf =  new StringBuffer(4);
   int t = Math.abs(n);

   while(t!=0) {
       int c = t%10;
       char p = (char)(c+'0');
       sbf.append(p);
       t = t /10;
   }
   sbf.reverse();
   if(n<0)
       sbf.insert(0,'-');
   String s = new String(sbf);
   if(s.length()== 0)
          s="0";



