/*
 * [373] Find K Pairs with Smallest Sums
 *
 * https://leetcode.com/problems/find-k-pairs-with-smallest-sums/description/
 *
 * algorithms
 * Medium (31.03%)
 * Total Accepted:    35.5K
 * Total Submissions: 114.6K
 * Testcase Example:  '[1,7,11]\n[2,4,6]\n3'
 *
 * 
 * You are given two integer arrays nums1 and nums2 sorted in ascending order
 * and an integer k. 
 * 
 * 
 * Define a pair (u,v) which consists of one element from the first array and
 * one element from the second array.
 * 
 * Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
 * 
 * 
 * Example 1:
 * 
 * Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
 * 
 * Return: [1,2],[1,4],[1,6]
 * 
 * The first 3 pairs are returned from the sequence:
 * [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
 * 
 * 
 * 
 * Example 2:
 * 
 * Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2
 * 
 * Return: [1,1],[1,1]
 * 
 * The first 2 pairs are returned from the sequence:
 * [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
 * 
 * 
 * 
 * Example 3:
 * 
 * Given nums1 = [1,2], nums2 = [3],  k = 3 
 * 
 * Return: [1,3],[2,3]
 * 
 * All possible pairs are returned from the sequence:
 * [1,3],[2,3]
 * 
 * 
 * 
 * Credits:Special thanks to @elmirap and @StefanPochmann for adding this
 * problem and creating all test cases.
 */

class Solution {
class compare_class
{
    public :
        bool operator()(pair<int,int> a,pair<int,int> b) const {
            int sum1 = a.first+a.second;
            int sum2 = b.first+b.second;
            return sum1>sum2;
        }
};
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> ans;
        if (nums1.empty() || nums2.empty() || k<=0) return ans;
        int len1 = nums1.size();
        int len2 = nums2.size();
        
        compare_class functor;
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(functor)> pq;
        
        for (auto x :nums1) {
            for (auto y : nums2) {
                pair<int,int> tmp = make_pair(x,y);
                pq.push(tmp);
            }
        }
        if (k<=len1*len2) {
        while (k--) {
            ans.push_back(pq.top());
            pq.pop();
        } }
        else {
            int total = len1*len2;
            while (total--) {
                 ans.push_back(pq.top());
                pq.pop();
            }
        }
        
        return ans;
        
    }
    

};
