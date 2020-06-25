/*
 * [680] Valid Palindrome II
 *
 * https://leetcode.com/problems/valid-palindrome-ii/description/
 *
 * algorithms
 * Easy (32.60%)
 * Total Accepted:    17K
 * Total Submissions: 52K
 * Testcase Example:  '"aba"'
 *
 * 
 * Given a non-empty string s, you may delete at most one character.  Judge
 * whether you can make it a palindrome.
 * 
 * 
 * Example 1:
 * 
 * Input: "aba"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "abca"
 * Output: True
 * Explanation: You could delete the character 'c'.
 * 
 * 
 * 
 * Note:
 * 
 * The string will only contain lowercase characters a-z.
 * The maximum length of the string is 50000.
 * 
 * 
 */
class Solution {
public:
   
    bool validPalindrome(string s) {
        int len = s.size();
        int begin = 0;
        int end =  len - 1;
        while (begin < end) {
            if (s[begin] == s[end]) {            
            begin++;
            end--;
            } else break;
        }
        if (s[begin] == s[end]) return true;
        string rdeleteone = s;
        rdeleteone.erase(rdeleteone.begin()+begin);
        string deleteone = rdeleteone;
        reverse(rdeleteone.begin(),rdeleteone.end());
        if (rdeleteone == deleteone) return true;
        rdeleteone = s;
        rdeleteone.erase(rdeleteone.begin()+end);
        deleteone = rdeleteone;
        reverse(rdeleteone.begin(),rdeleteone.end());
        if (deleteone == rdeleteone) return true;
        
        return false;
    }
};
