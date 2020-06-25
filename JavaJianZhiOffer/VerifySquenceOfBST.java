public class VerifySquenceOfBST {
    public boolean VerifySquenceOfBST(int [] sequence) {
        if (sequence == null || sequence.length == 0) 
        	return false;
        if (sequence.length == 1)
        	return true;
        return ju(sequence,0,sequence.length-1);
    }
    public boolean ju(int[] sequence,int start,int root) {
    	if (start >= root)
    		return true;
    	int i  = root;
    	while (i> start && sequence[i-1]>sequence[root])
    		i--;
    	for (int j = start; j < i - 1;j++) {
    		if (sequence[j] > sequence[root])
    			return false;
    	}
    	return ju(sequence,start,i-1) && ju(sequence,i,root-1);
    }
        
}