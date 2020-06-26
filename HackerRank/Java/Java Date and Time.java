//https://www.hackerrank.com/challenges/java-date-and-time/problem
import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.util.Calendar;

public class Solution {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String month = in.next();
        String day = in.next();
        String year = in.next();

        Calendar c =  Calendar.getInstance();

        int iyear = Integer.parseInt(year);
        int imonth = Integer.parseInt(month);
        int iday = Integer.parseInt(day);
        c.set(iyear,imonth-1,iday);
        String[] weeks = {"", "SUNDAY","MONDAY","TUESDAY", "WEDNESDAY", "THURSDAY","FRIDAY","SATURDAY"};
        int dayofweek = c.get(Calendar.DAY_OF_WEEK);
        System.out.println(weeks[dayofweek]);

    }
}
