public class GetNumberOfK {
    public int GetNumberOfK(int[] nums, int target) {
        int left = 0;
        int right = nums.length;
        if (nums.length == 0) {
            return 0;
        }

        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                right = mid;
            } else if (nums[mid] > target) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            }
        }

        if (left >= nums.length || nums[left] != target) {
            return 0;
        }

        int ans = 0;
        for (int i = left; i < nums.length; ++i) {
            if (nums[i] == target) {
                ans++;
            }
        }

        return ans;
    }
}
