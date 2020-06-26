//https://www.hackerrank.com/challenges/java-generics/problem
class Printer
{
   //Write your code here
    public <T> void printArray(T[] arry) {
        for(T x : arry)
            System.out.println(x);

    }
}
