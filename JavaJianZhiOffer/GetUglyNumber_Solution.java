public class GetUglyNumber_Solution {
    public int GetUglyNumber_Solution(int index) {
    	if (index <= 0)
    		return 0;
    	int[] uglynumber = new int[index];
    	
    	uglynumber[0] = 1;
    	
    	int p2 = 0;
    	int p3 = 0;
    	int p5 = 0;
    	
    	int cur = 1;
    	
    	while (cur < index) {
    		int curnumber = Math.min(Math.min(uglynumber[p2]*2,uglynumber[p3]*3),uglynumber[p5]*5);
    		uglynumber[cur] = curnumber;
    		
    		while (uglynumber[p2]*2 <= uglynumber[cur])
    			p2++;
    		while (uglynumber[p3]*3 <= uglynumber[cur])
    			p3++;
    		while (uglynumber[p5]*5 <= uglynumber[cur])
    			p5++;
    		
    		cur++;
    	}
    	
    	return uglynumber[index-1];
    }

	
}