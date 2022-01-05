import java.util.ArrayList;
public class Multiply {
    public int[] Multiply(int[] A) {
        if (A == null  || A.length == 0) 
        	return A;
        int[] left = new int[A.length];
        int[] right = new int[A.length];
        left[0] = 1;
        right[A.length-1] = 1;
        for (int i = 1;i < A.length;i++) {
        	left[i] = left[i-1]*A[i-1];
        }
        for (int i = A.length-2;i>=0;i--) {
        	right[i] = right[i+1]*A[i+1];
        }
        int[] B = new int[A.length];
        
        for (int i = 0; i < A.length;i++) {
        	B[i] = left[i] * right[i];
        }
        
        return B;
        
    }
}