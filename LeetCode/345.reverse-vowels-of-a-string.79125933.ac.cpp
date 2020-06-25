/*
 * [345] Reverse Vowels of a String
 *
 * https://leetcode.com/problems/reverse-vowels-of-a-string/description/
 *
 * algorithms
 * Easy (38.87%)
 * Total Accepted:    96.3K
 * Total Submissions: 247.7K
 * Testcase Example:  '"hello"'
 *
 * Write a function that takes a string as input and reverse only the vowels of
 * a string.
 * 
 * 
 * Example 1:
 * Given s = "hello", return "holle".
 * 
 * 
 * 
 * Example 2:
 * Given s = "leetcode", return "leotcede".
 * 
 * 
 * 
 * Note:
 * The vowels does not include the letter "y".
 * 
 */
class Solution {
public:
    bool isVowels(char c)
    {
        if(c == 'a' || c=='e' || c == 'i' || c=='o'||c == 'u'|| c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
            return true;
        else
            return false;
    }
    string reverseVowels(string s) {
        string::iterator itb = s.begin();
        string::iterator ite = prev(s.end());
        while(itb<=ite)
        {
            if(isVowels(*itb) && isVowels(*ite)){
                char t;
                t = *ite;
                *ite = *itb;
                *itb = t;
                itb++;
                ite--;
            }
            else if(isVowels(*itb)){
                ite--;
            }
            else if(isVowels(*ite)){
                itb++;
            }
            else
            {
                itb++;
                ite--;
            }
        }
        return s;
    }
};
