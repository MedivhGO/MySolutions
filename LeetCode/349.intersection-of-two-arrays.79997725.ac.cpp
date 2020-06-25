/*
 * [349] Intersection of Two Arrays
 *
 * https://leetcode.com/problems/intersection-of-two-arrays/description/
 *
 * algorithms
 * Easy (47.78%)
 * Total Accepted:    114.7K
 * Total Submissions: 240.2K
 * Testcase Example:  '[]\n[]'
 *
 * 
 * Given two arrays, write a function to compute their intersection.
 * 
 * 
 * Example:
 * Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
 * 
 * 
 * Note:
 * 
 * Each element in the result must be unique.
 * The result can be in any order.
 * 
 * 
 */
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
    
        sort(nums1.begin(),nums1.end());
        sort(nums1.begin(),nums1.end());
        for(int i=0;i<nums1.size();i++)
        {
               if(find(nums2.begin(),nums2.end(),nums1[i])!=nums2.end()){
                    result.push_back(nums1[i]);
                    continue;
               }
        }
        auto it = unique(result.begin(),result.end());
        vector<int> final11(result.begin(),it);

        return final11;
    }
};
