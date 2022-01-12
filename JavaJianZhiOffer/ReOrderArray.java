public class ReOrderArray {
    public void ReOrderArray(int [] array) {
        if (array == null) return ;
        int len = array.length;
        int pre = 0;
        int later = len-1;
        while (pre < later) {
            while (pre < later && array[pre] %2 !=0) {
                pre++;
            }
            while (pre < later && array[later]%2 == 0) {
                later--;
            }
            
            if (pre < later) {
                int t = array[pre];
                array[pre] = array[later];
                array[later] = t;
            }
        }
        return ;
    }
    public static void main(String[] args) {
        
    }
}