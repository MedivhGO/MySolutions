public class LeftRotateString {
    public static String LeftRotateString(String str,int n) {
        if (str == null) return "";
        int len = str.length();
        if (len == 0) return "";
        int rot = n%len;

        StringBuffer sb1 = new StringBuffer(str.substring(0, rot));
        StringBuffer sb2 = new StringBuffer(str.substring(rot, len));
        sb1.reverse();
        sb2.reverse();
        StringBuffer sb3 = sb1.append(sb2);
        sb3.reverse();
        return sb3.toString();
    }
    public static void main(String[] args) {
        String s= "abcXYZdef";
        System.out.println(LeftRotateString(s,3));
    }
}