/*
 * [645] Set Mismatch
 *
 * https://leetcode.com/problems/set-mismatch/description/
 *
 * algorithms
 * Easy (39.95%)
 * Total Accepted:    20K
 * Total Submissions: 50.1K
 * Testcase Example:  '[1,2,2,4]'
 *
 * 
 * The set S originally contains numbers from 1 to n. But unfortunately, due to
 * the data error, one of the numbers in the set got duplicated to another
 * number in the set, which results in repetition of one number and loss of
 * another number. 
 * 
 * 
 * 
 * Given an array nums representing the data status of this set after the
 * error. Your task is to firstly find the number occurs twice and then find
 * the number that is missing. Return them in the form of an array.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: nums = [1,2,2,4]
 * Output: [2,3]
 * 
 * 
 * 
 * Note:
 * 
 * The given array size will in the range [2, 10000].
 * The given array's numbers won't have any order.
 * 
 * 
 */
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        if (nums.empty()) return ans;
        int len = nums.size();
        int shouldsum = len*(len+1)/2;
       
        int realsum = accumulate(nums.begin(),nums.end(),0);
        unordered_set<int> iset;
        for (auto x : nums) {
            auto t = iset.insert(x);
            if (t.second == false)
                ans.push_back(x);
        }
        realsum = realsum-ans[0];
        
        ans.push_back(shouldsum-realsum);
        
        return ans;
    }
};
