public class FindContinuousSequence {
  public int[][] findContinuousSequence(int target) {
        int left = 1;
        int right = 1;
        ArrayList<int[]> ans = new ArrayList<>();
        while (right < target) {
            int cur_arr_sum = (right - left) * (left + right - 1) / 2;
            if (cur_arr_sum > target) {
                left++;
            } else if (cur_arr_sum < target) {
                right++;
            } else {
                int tmp[] = new int[right - left];
                for (int i = left; i < right; ++i) {
                    tmp[i - left] = i;
                }
                ans.add(tmp);
                left++;
            }
        }
        return ans.toArray(new int[ans.size()][]);        
    }
}
