/*
 * [4] Median of Two Sorted Arrays
 *
 * https://leetcode.com/problems/median-of-two-sorted-arrays/description/
 *
 * algorithms
 * Hard (22.53%)
 * Total Accepted:    220.7K
 * Total Submissions: 979.8K
 * Testcase Example:  '[1,3]\n[2]'
 *
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * 
 * Find the median of the two sorted arrays. The overall run time complexity
 * should be O(log (m+n)).
 * 
 * Example 1:
 * 
 * nums1 = [1, 3]
 * nums2 = [2]
 * 
 * The median is 2.0
 * 
 * 
 * 
 * Example 2:
 * 
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * 
 * The median is (2 + 3)/2 = 2.5
 * 
 * 
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        const int m = nums1.size();
        const int n = nums2.size();
        
        int total  = m+n;
        
        if (total & 0x1) //判断total是奇数还是偶数，奇数iｆ语句成立
            return find_kth(nums1.begin(),m,nums2.begin(),n,total/2+1);
        else 
            return (find_kth(nums1.begin(),m,nums2.begin(),n,total/2) + find_kth(nums1.begin(),m,nums2.begin(),n,total/2+1)) /2.0;
            
    }
private:
    static int find_kth(std::vector<int>::const_iterator A,int m,std::vector<int>::const_iterator B,int n,int k) {
        
        //always assume that m is equal or smaller than n
        if (m >n) return find_kth(B,n,A,m,k);
        if (m == 0)  return *(B+k-1);
        if (k == 1)  return min(*A,*B);
        
        //divide k into two part
        
        int ia = min(k/2,m),ib = k-ia;
        
        if (*(A+ia-1) < *(B+ib-1))
            return find_kth(A+ia,m-ia,B,n,k-ia); // 从ia个元素之后开始找，已经确定了ia个元素 在k个元素之前
        else if (*(A+ia-1)>*(B+ib-1))
            return find_kth(A,m,B+ib,n-ib,k-ib);
        else
            return A[ia-1];
        
        
    }
};
