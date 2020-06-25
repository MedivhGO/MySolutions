/*
 * [415] Add Strings
 *
 * https://leetcode.com/problems/add-strings/description/
 *
 * algorithms
 * Easy (41.69%)
 * Total Accepted:    48.9K
 * Total Submissions: 117.2K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as string, return
 * the sum of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 5100.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        vector<int> inum1,inum2;
        for(auto x : num1) {
            inum1.push_back(x-'0');
        }
        for(auto x : num2) {
            inum2.push_back(x-'0');
        }
        reverse(inum1.begin(),inum1.end());
        reverse(inum2.begin(),inum2.end());
        int opres = max(len1,len2);
        int carry=0;
        vector<int> res(opres+1);
        for(int i=0;i<opres;i++) {
            if(i>len1-1) {
                inum1.push_back(0);
            }
            else{
                inum2.push_back(0);
            }
            int nu = (inum1[i]+inum2[i]+carry)%10;
            res[i] = nu;
            carry = (inum1[i]+inum2[i]+carry)/10;
        }
        if(carry==1)
            res[opres] = 1;
        string sres;
        for(int i=0;i<res.size()-1;i++) {
            sres.push_back(res[i]+'0');
        }
        if(res[res.size()-1]==1)
            sres.push_back('1');
        reverse(sres.begin(),sres.end());
       
        return sres;
    }
};
