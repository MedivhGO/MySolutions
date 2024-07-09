class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        int total = len1 + len2;
        if (total % 2 != 0) {
            return findKth(nums1, 0, len1, nums2, 0, len2, total/2 + 1);
        }
        int mid1 = findKth(nums1, 0, len1, nums2, 0, len2, total/2);
        int mid2 = findKth(nums1, 0, len1, nums2, 0, len2, total/2 + 1);
        return (mid1 + mid2) / 2.0;
    }

    int findKth(vector<int>& nums1, int i, int end1, vector<int>& nums2, int j, int end2, int k) {
            if (end1 - i > end2 - j) { // 保证 nums1 的元素比 nums2 中的元素少
                return findKth(nums2, j, end2, nums1, i, end1, k);
            }
            if (i == end1) {
                return nums2[j+ k-1];
            }
            if (k == 1) {
                return min(nums1[i], nums2[j]);
            }
            int si = min(i + k/2, end1);
            int sj = j + k / 2;
            if (nums1[si-1] > nums2[sj-1]) {
                return findKth(nums1, i, end1, nums2, j + k/2, end2, k - k/2);
            }
            return findKth(nums1, si, end1, nums2, j, end2, k-(si-i));
    }
};