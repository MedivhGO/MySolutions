/*
 * [557] Reverse Words in a String III
 *
 * https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
 *
 * algorithms
 * Easy (59.88%)
 * Total Accepted:    54.3K
 * Total Submissions: 90.6K
 * Testcase Example:  '"Let\'s take LeetCode contest"'
 *
 * Given a string, you need to reverse the order of characters in each word
 * within a sentence while still preserving whitespace and initial word order.
 * 
 * Example 1:
 * 
 * Input: "Let's take LeetCode contest"
 * Output: "s'teL ekat edoCteeL tsetnoc"
 * 
 * 
 * 
 * Note:
 * In the string, each word is separated by single space and there will not be
 * any extra space in the string.
 * 
 */
class Solution {
public:
    string reverseWords(string s) {
        string::iterator  oldit=s.begin(),nit = s.begin() ;
        nit = find(nit,s.end(),' ');
        while(nit != s.end()) {
            
            
            reverse(oldit,nit);
            oldit = nit+1;
            nit = find(oldit,s.end(),' ');
        }
        reverse(oldit,s.end());             
        return s;
    }
};
