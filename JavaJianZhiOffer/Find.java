public class Find {
    public boolean Find(int target, int [][] array) {
        if (array == null) return false;
        int row = array.length;
        int col = array[0].length;
      
        int prowfirst = 0;
        int pcollast = col-1;
        while (prowfirst < row && pcollast >=0) {
            if (target > array[prowfirst][pcollast]) {
                prowfirst++;
            } else if (target < array[prowfirst][pcollast]) {
                pcollast--;
            } else {
                return true;
            }
        }
        
        return false;
        
    }
    public static void main(String[] args) {
        
    }
}