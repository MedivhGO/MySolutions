/*
 * [125] Valid Palindrome
 *
 * https://leetcode.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (26.73%)
 * Total Accepted:    197.4K
 * Total Submissions: 738.5K
 * Testcase Example:  '""'
 *
 * 
 * Given a string, determine if it is a palindrome, considering only
 * alphanumeric characters and ignoring cases.
 * 
 * 
 * 
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 * 
 * 
 * 
 * Note:
 * Have you consider that the string might be empty? This is a good question to
 * ask during an interview.
 * 
 * For the purpose of this problem, we define empty string as valid palindrome.
 * 
 */
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty()) return true;
        transform(s.begin(),s.end(),s.begin(),::tolower);
        auto left = s.begin(),right = prev(s.end());
        while(left <= right)
        {
            if(!::isalnum(*left)) left++;
            else if(!::isalnum(*right)) right--;
            else if(*left != *right){
                return false;
            }
            else{
                left++;
                right--;
            }
        }
        return true;
    }
};
