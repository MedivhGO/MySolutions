/*
 * [290] Word Pattern
 *
 * https://leetcode.com/problems/word-pattern/description/
 *
 * algorithms
 * Easy (33.29%)
 * Total Accepted:    94K
 * Total Submissions: 282.3K
 * Testcase Example:  '"abba"\n"dog cat cat dog"'
 *
 * Given a pattern and a string str, find if str follows the same pattern.
 * ⁠Here follow means a full match, such that there is a bijection between a
 * letter in pattern and a non-empty word in str.
 * 
 * Examples:
 * 
 * pattern = "abba", str = "dog cat cat dog" should return true.
 * pattern = "abba", str = "dog cat cat fish" should return false.
 * pattern = "aaaa", str = "dog cat cat dog" should return false.
 * pattern = "abba", str = "dog dog dog dog" should return false.
 * 
 * 
 * 
 * 
 * Notes:
 * You may assume pattern contains only lowercase letters, and str contains
 * lowercase letters separated by a single space.
 * 
 * 
 * Credits:Special thanks to @minglotus6 for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    bool foo (vector<int> v1,vector<int> v2) {
        if(v1.size() != v2.size())
            return false;
        else {
            for(int i=0;i<v1.size();i++) {
                if(v1[i]!=v2[i])
                    return false;
            }
            return true;
        }
            
    }
    bool wordPattern(string pattern, string str) {
        unordered_map<char,vector<int> > mapping;
        const int patternlen = pattern.size();
        for(int i=0;i<patternlen;i++) {
            mapping[pattern[i]].push_back(i);
        }
        unordered_map<string,vector<int> > mapping1;
        istringstream in(str);
        vector<string> svec;
        int strlen = 0;
        for (string word;in>>word;strlen++) {
            mapping1[word].push_back(strlen);
            svec.push_back(word);
        };
        if(patternlen!=strlen)
            return false;
        for (int i=0;i<strlen;i++) {
            vector<int> v1 = mapping[pattern[i]];
            vector<int> v2 = mapping1[svec[i]];
            if(!foo(v1,v2))
                return false;
        }
        return true;
        
      
       
            
       
        
    }
};
