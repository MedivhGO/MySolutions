public class FindNumsAppearOnce {
  public int[] FindNumsAppearOnce(int[] nums) {
        int diff_xor = 0;
        for (int i = 0; i < nums.length; ++i) {
            diff_xor ^= nums[i];
        }
        int div_num = 1;
        while ((diff_xor & div_num) == 0) {
            div_num <<= 1;
        }
        int ans1 = 0;
        int ans2 = 0;
        for (int i = 0; i < nums.length; ++i) {
            if ((nums[i] & div_num) != 0) {
                ans1 ^= nums[i];
            } else {
                ans2 ^= nums[i];
            }
        }
        return new int[]{ans1, ans2};
    }
}
