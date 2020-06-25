/*
 * [229] Majority Element II
 *
 * https://leetcode.com/problems/majority-element-ii/description/
 *
 * algorithms
 * Medium (28.95%)
 * Total Accepted:    65.1K
 * Total Submissions: 224.9K
 * Testcase Example:  '[]'
 *
 * Given an integer array of size n, find all elements that appear more than ⌊
 * n/3 ⌋ times. The algorithm should run in linear time and in O(1) space.
 */
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
      int cnt1 = 0, cnt2 = 0, a=0, b=1;
        //a,b随便给的值，并不影响结果
      for(auto n: nums){
        if (a==n){
            cnt1++;
        }
        else if (b==n){
            cnt2++;
        }
        else if (cnt1==0){ //a，b不能同时赋予0值
            a = n;
            cnt1 = 1;
        }
        else if (cnt2 == 0){
            b = n;
            cnt2 = 1;
        }
        else{
            cnt1--;
            cnt2--;
        }
    }
    
    cnt1 = cnt2 = 0;
    for(auto n: nums){
        if (n==a)   cnt1++;
        else if (n==b)  cnt2++;
    }
    
    vector<int> res;
    if (cnt1 > nums.size()/3)   res.push_back(a);
    if (cnt2 > nums.size()/3)   res.push_back(b);
    return res;
    }
};
