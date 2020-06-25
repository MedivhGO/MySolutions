/*
 * [500] Keyboard Row
 *
 * https://leetcode.com/problems/keyboard-row/description/
 *
 * algorithms
 * Easy (59.83%)
 * Total Accepted:    51.7K
 * Total Submissions: 86.4K
 * Testcase Example:  '["Hello","Alaska","Dad","Peace"]'
 *
 * Given a List of words, return the words that can be typed using letters of
 * alphabet on only one row's of American keyboard like the image
 * below. 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: ["Hello", "Alaska", "Dad", "Peace"]
 * Output: ["Alaska", "Dad"]
 * 
 * 
 * 
 * Note:
 * 
 * You may use one character in the keyboard more than once.
 * You may assume the input string will only contain letters of alphabet.
 * 
 * 
 */
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        
        string s1 = "qwertyuiop";
        string s2 = "asdfghjkl";
        string s3 = "zxcvbnm";
        for(auto s : words) {
            int m=0,k=0,n=0;
            for(int i=0;i<s.size();i++) {
                if( s1.find(tolower(s[i]))!= std::string::npos)
                        m++;
                else if (s2.find(tolower(s[i]))!=std::string::npos)
                        k++;
                else
                        n++;
            }
            if(m == s.size() || n == s.size() ||  k == s.size())
                    res.push_back(s);
            
        }
        return res;
        
    }
};
