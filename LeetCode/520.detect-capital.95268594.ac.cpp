/*
 * [520] Detect Capital
 *
 * https://leetcode.com/problems/detect-capital/description/
 *
 * algorithms
 * Easy (52.01%)
 * Total Accepted:    46.2K
 * Total Submissions: 88.8K
 * Testcase Example:  '"USA"'
 *
 * 
 * Given a word, you need to judge whether the usage of capitals in it is right
 * or not.
 * 
 * 
 * 
 * We define the usage of capitals in a word to be right when one of the
 * following cases holds:
 * 
 * All letters in this word are capitals, like "USA".
 * All letters in this word are not capitals, like "leetcode".
 * Only the first letter in this word is capital if it has more than one
 * letter, like "Google".
 * 
 * Otherwise, we define that this word doesn't use capitals in a right way.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: "USA"
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: "FlaG"
 * Output: False
 * 
 * 
 * 
 * Note:
 * The input will be a non-empty word consisting of uppercase and lowercase
 * latin letters.
 * 
 */
class Solution {
public:
    bool detectCapitalUse(string word) {
       
       
        if(word[0]>=97 && word[0] <= 122) {
         for(int i=1;i<word.size();i++) 
                if(word[i]<97 || word[i]>122)
                    return false;
         return true;
        }
        else if(word[0]>=65 && word[0] <= 90) {
             int m=0,n=0;
             for(int i=1;i<word.size();i++) {
                if(word[i]>=65 && word[i] <= 90)
                     m++;
                else if(word[i] >= 90 && word[i]<=122)
                     n++;
             }
             if(m==word.size()-1)
                return true;
             if(n == word.size() -1) 
                return true;
             return false;
        }
    }
};
