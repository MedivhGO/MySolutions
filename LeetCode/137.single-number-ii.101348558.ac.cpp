/*
 * [137] Single Number II
 *
 * https://leetcode.com/problems/single-number-ii/description/
 *
 * algorithms
 * Medium (42.22%)
 * Total Accepted:    128K
 * Total Submissions: 303.2K
 * Testcase Example:  '[1]'
 *
 * 
 * Given an array of integers, every element appears three times except for
 * one, which appears exactly once. Find that single one.
 * 
 * 
 * 
 * Note:
 * Your algorithm should have a linear runtime complexity. Could you implement
 * it without using extra memory?
 * 
 */
class Solution {
public:
   
    int singleNumber(vector<int>& nums) {
        vector<long> numsl;
       // ostream_iterator<long> oo(cout," ");
        int ans = 0;
        int len = nums.size();
        int weight =0 ;
        int flag = 0;
        //cal the symbol of the result
        int countsym[2] = {0,0};
        for (int i=0;i<len;i++) {
            if (nums[i]>=0){
                countsym[1]++;
                numsl.push_back(nums[i]);
            }
            else {
                countsym[0]++;
                numsl.push_back(-(long)nums[i]);
            }
        }
        if (countsym[1]%3 == 0)
                flag = 0;
        else
                flag = 1;
        
        
        //copy(numsl.begin(),numsl.end(),oo);
        while(true) {
            int countZero = 0;
            int colcount[2] = {0,0};
            
            for (int i=0;i<nums.size();i++) {
                
                if (numsl[i] == 0) countZero++;
                colcount[numsl[i]%2]++;
                numsl[i] = numsl[i]>>1;
            }
            if (colcount[0]%3 == 0)
                ans+=1*pow(2,weight);
            else
                ans+=0;
            weight++;
            if (countZero == len) {
                if (flag == 0)
                    return -ans;
                else
                    return ans; 
                
            }
        }
    }
};
