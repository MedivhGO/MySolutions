/*
 * [205] Isomorphic Strings
 *
 * https://leetcode.com/problems/isomorphic-strings/description/
 *
 * algorithms
 * Easy (34.38%)
 * Total Accepted:    124.2K
 * Total Submissions: 361.2K
 * Testcase Example:  '"egg"\n"add"'
 *
 * Given two strings s and t, determine if they are isomorphic.
 * 
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 * 
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character but a character may map to itself.
 * 
 * For example,
 * Given "egg", "add", return true.
 * 
 * Given "foo", "bar", return false.
 * 
 * Given "paper", "title", return true.
 * 
 * Note:
 * You may assume both s and t have the same length.
 */
class Solution {
public:
    bool fun(vector<int> v1,vector<int> v2) {
        if(v1.size()!=v2.size())
            return false;
        for(int i=0;i<v1.size();i++) {
            if(v1[i]!=v2[i])
                return false;
        }
        return true;
    }
    bool isIsomorphic(string s, string t) {
        unordered_map<char,vector<int> > map1;
        unordered_map<char,vector<int> > map2;
        const int slen = s.size();
        const int tlen = t.size();
        if(slen != tlen)
            return false;
        for(int i=0; i<slen; i++) {
            map1[s[i]].push_back(i);
            map2[t[i]].push_back(i);
        }
        for(int i=0; i<slen; i++) {
            vector<int> v1 = map1[s[i]];
            vector<int> v2 = map2[t[i]];
            if(!fun(v1,v2))
                return false;
        }
        return true;
        
        
    }
};
