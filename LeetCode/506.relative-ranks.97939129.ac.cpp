/*
 * [506] Relative Ranks
 *
 * https://leetcode.com/problems/relative-ranks/description/
 *
 * algorithms
 * Easy (46.68%)
 * Total Accepted:    25.6K
 * Total Submissions: 54.7K
 * Testcase Example:  '[5,4,3,2,1]'
 *
 * 
 * Given scores of N athletes, find their relative ranks and the people with
 * the top three highest scores, who will be awarded medals: "Gold Medal",
 * "Silver Medal" and "Bronze Medal".
 * 
 * Example 1:
 * 
 * Input: [5, 4, 3, 2, 1]
 * Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
 * Explanation: The first three athletes got the top three highest scores, so
 * they got "Gold Medal", "Silver Medal" and "Bronze Medal". For the left two
 * athletes, you just need to output their relative ranks according to their
 * scores.
 * 
 * 
 * 
 * Note:
 * 
 * N is a positive integer and won't exceed 10,000.
 * All the scores of athletes are guaranteed to be unique.
 * 
 * 
 * 
 */
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        string f = "Gold Medal";
        string s = "Silver Medal";
        string t = "Bronze Medal";
        
        unordered_map <int,size_t> mapping;
        
        for (int i =0 ; i < nums.size() ; i++ ) {
            int count = 0;
            for ( int j = 0 ; j < nums.size() ; j++) {
                if (nums[i] > nums[j])
                    count++;
            }
            mapping[nums[i]] = count;
        }
        
        vector<string> ans;
        
        for ( int i = 0 ; i < nums.size() ; i++ ) {
            int order = nums.size() - mapping[nums[i]];
            
            if (order == 1)
                ans.push_back(f);
            else if (order == 2) 
                ans.push_back(s);
            else if (order == 3)
                ans.push_back(t);
            else {
               stringstream st;
               st << order;
               string s;
               st >> s;
               ans.push_back(s);
            }
               
        }
        
        return ans;
    }  
};
