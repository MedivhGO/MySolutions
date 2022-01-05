public class Duplicate {
    // Parameters:
    //    numbers:     an array of integers
    //    length:      the length of array numbers
    //    duplication: (Output) the duplicated number in the array number,length of duplication array is 1,so using duplication[0] = ? in implementation;
    //                  Here duplication like pointor in C/C++, duplication[0] equal *duplication in C/C++
    //    这里要特别注意~返回任意重复的一个，赋值duplication[0]
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    public static boolean Duplicate(int numbers[],int length,int [] duplication) {
    		if (numbers == null) return false;
    		for (int i = 0; i < length;i++) {
    			if (numbers[i] < 0 || numbers[i] > length-1)
    				return false;
    		}
    		for (int i = 0;i < length;i++) {
    			
    				numbers[Math.abs(numbers[i])] = -numbers[Math.abs(numbers[i])];
    				if(numbers[Math.abs(numbers[i])]>0) {
    					duplication[0] = Math.abs(numbers[i]);
    					return true;
    				}
    		}
    		return false;
    }
    public static boolean Duplicate1(int numbers[],int length,int [] duplication) {
    	if (numbers == null) return false;
    	for (int i = 0; i < length;i++) {
			if (numbers[i] < 0 || numbers[i] > length-1)
				return false;
		}
    	for (int i = 0; i < length;i++) {
    		
    		while (i != numbers[i]) {
    			if (numbers[i] == numbers[numbers[i]]) {
    				duplication[0] = numbers[i];
    				return true;
    			} else {
    				int temp = numbers[i];
    				numbers[i] = numbers[temp];
    				numbers[temp] = temp;
    			}
    		}
    	
    	}
    	return false;
    	
    }
    public static void main(String[] args) {
    	int[] arr = {2,4,3,1,4};
    	int[] ans = new int[1];
    	System.out.println(Duplicate(arr,5,ans));
    	System.out.println(ans[0]);
    }
    
}