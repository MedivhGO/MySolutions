import java.util.ArrayList;
public class FindNumbersWithSum {
    public static ArrayList<Integer> FindNumbersWithSum(int [] array,int sum) {
        ArrayList<Integer> al = new ArrayList<Integer>();
        if (array == null) return al;
        int len = array.length;
        int left = 0,right = len-1;
        int product = 999;
        while (left<=right) {
            System.out.println(left);
            System.out.println(right);
            if (array[left]+array[right] > sum) {
                right--;
            } else if (array[left]+array[right] < sum) {
                left++;
            } else {
                if (array[left]*array[right]<product) {
                    al.add(array[left]);
                    al.add(array[right]);
                    product = array[left]*array[right];
                }
            }
            left++;
            right--;
        }
        if (al.isEmpty() == true)
            return al;
        ArrayList<Integer> ans = new ArrayList<Integer>();
        ans.add(al.get(al.size()-2));
        ans.add(al.get(al.size()-1));
        
        return ans;
    }
    public static void main(String[] args) {
        int[] t= {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
        System.out.println(FindNumbersWithSum(t,21));
    }
}