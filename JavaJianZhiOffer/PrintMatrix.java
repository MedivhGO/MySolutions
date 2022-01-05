import java.util.ArrayList;
public class PrintMatrix {
    public ArrayList<Integer> PrintMatrix(int [][] matrix) {
        ArrayList<Integer> al = new ArrayList<Integer>();
        if (matrix == null) return al;
        int row = matrix.length;
        if (row == 0) return al;
        int col = matrix[0].length;
        int beginX = 0,endX = col-1;
        int beginY = 0,endY = row-1;
        while (true) {
     	   	
     	      for (int i = beginX;i <=endX;i++) al.add(matrix[beginY][i]);
     	      beginY++;
     	      if (beginY > endY) break;
     	      for (int i = beginY;i<=endY;i++) al.add(matrix[i][endX]) ;
     	      endX--;
     	      if (endX < beginX) break;
     	      for (int i = endX;i >= beginX;i--) al.add(matrix[endY][i]);
     	      endY--;
     	      if (endY < beginY) break;
     	      for (int i = endY;i>=beginY;i--) al.add(matrix[i][beginX]);
     	      beginX++;
     	      if (beginX>endX) break;

        }
        return al;
    }
    public static void main(String[] args) {
    	
    }
}