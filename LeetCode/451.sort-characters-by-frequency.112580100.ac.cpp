/*
 * [451] Sort Characters By Frequency
 *
 * https://leetcode.com/problems/sort-characters-by-frequency/description/
 *
 * algorithms
 * Medium (51.39%)
 * Total Accepted:    44K
 * Total Submissions: 85.6K
 * Testcase Example:  '"tree"'
 *
 * Given a string, sort it in decreasing order based on the frequency of
 * characters.
 * 
 * Example 1:
 * 
 * Input:
 * "tree"
 * 
 * Output:
 * "eert"
 * 
 * Explanation:
 * 'e' appears twice while 'r' and 't' both appear once.
 * So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid
 * answer.
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * "cccaaa"
 * 
 * Output:
 * "cccaaa"
 * 
 * Explanation:
 * Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
 * Note that "cacaca" is incorrect, as the same characters must be together.
 * 
 * 
 * 
 * Example 3:
 * 
 * Input:
 * "Aabb"
 * 
 * Output:
 * "bbAa"
 * 
 * Explanation:
 * "bbaA" is also a valid answer, but "Aabb" is incorrect.
 * Note that 'A' and 'a' are treated as two different characters.
 * 
 * 
 */
class Solution {
public:
    string frequencySort(string s) {
        string ans;
        if (s.empty())
            return ans;
        unordered_map<char,size_t> m;
        vector<string> bucket(s.size()+1,"");
        for (auto x : s) {
            m[x]++;
        }
        for (auto x : m) {
            int n = x.second;
            char c = x.first;
            bucket[n].append(n,c);
        }
        for (int i = s.size();i>=1;i--) {
            if (bucket[i]!= "")
                ans.append(bucket[i]);
        }
        return ans;
    }
};
