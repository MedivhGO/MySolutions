import java.util.ArrayList;

public class MovingCount {
    int ans = 0;
    public int MovingCount(int threshold, int rows, int cols)
    {
        
        if (rows <0 || cols <0) return ans;
        ArrayList<Boolean> table = new ArrayList<Boolean>();
        for (int i = 0; i < cols*rows;i++) {
        	table.add(false);
        }
        
        fun(threshold,0,0,rows,cols,table);
        return ans;
    }
    public void fun(int threshold,int row,int col,int rows,int  cols,ArrayList<Boolean> table) {
        if (row>rows || col>cols) {
            return;
        } else if (cal(row)+cal(col)>threshold) {
            return ;
        }else if (table.get(row*cols+col) == true){
            return ;	
        }
        else {
            table.set(row*cols+col, true);
            ans++;
            if (row+1<rows)
                fun(threshold,row+1,col,rows,cols,table);
            if (row-1>=0)
                 fun(threshold,row-1,col,rows,cols,table);
            if (col+1<cols) 
                 fun(threshold,row,col+1,rows,cols,table);
            if (col-1>=0) 
                 fun(threshold,row,col-1,rows,cols,table);
            return;
        }
    }
    int cal(int num) {
        int ans = 0;
        while (num!=0) {
            ans+=num%10;
            num = num/10;
        }
        return ans;
    }
}