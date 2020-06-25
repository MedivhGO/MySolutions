/*
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (36.51%)
 * Total Accepted:    16.3K
 * Total Submissions: 44.7K
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, write a function to return true if s2 contains
 * the permutation of s1. In other words, one of the first string's
 * permutations is the substring of the second string.
 * 
 * Example 1:
 * 
 * Input:s1 = "ab" s2 = "eidbaooo"
 * Output:True
 * Explanation: s2 contains one permutation of s1 ("ba").
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:s1= "ab" s2 = "eidboaoo"
 * Output: False
 * 
 * 
 * 
 * Note:
 * 
 * The input strings only contain lower case letters.
 * The length of both given strings is in range [1, 10,000].
 * 
 * 
 */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1len = s1.size(),s2len = s2.size();
        if (s1len > s2len) return false;
        vector<int> m(26);
        for (auto x : s1) {
            m[x-'a']++;
        }
        vector<int> s1arr = m;
        auto itb = s2.begin();
        auto ite = itb+s1len;
        while(itb!=ite) {
            char t = *itb;
            m[t-'a']--;
            itb++;
        }
        if (judge(m)) return true;
       
        while(ite!=s2.end()) {
            char t = *(ite-s1len);
            m[t-'a']++;
            t = *ite;
            m[t-'a']--;
            if (judge(m)) return true;
            ite++;
        }
        return false;
        
        
        
    }
private:
     bool judge(const vector<int> &m) {
         for (auto x : m) {
             if (x!=0)
                 return false;
         }
         return true;
     }
};
