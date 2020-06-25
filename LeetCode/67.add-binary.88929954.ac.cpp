/*
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (33.50%)
 * Total Accepted:    178.8K
 * Total Submissions: 533.8K
 * Testcase Example:  '"0"\n"0"'
 *
 * 
 * Given two binary strings, return their sum (also a binary string).
 * 
 * 
 * 
 * For example,
 * a = "11"
 * b = "1"
 * Return "100".
 * 
 */
class Solution {
public:
    string addBinary(string a, string b) {
        if(a=="0" && b == "0")
            return "0";
        stringstream ss;
        ss<<a;
        bitset<128> ibt,iibt,res;
        ss>>ibt;
        ss.clear();
        ss<<b;
        ss>>iibt;
        int carry=0;
        for(int i=0;i<=ibt.size();i++) {
            if(ibt[i]==1 && iibt[i] == 1 && carry == 1) {
                res[i] = 1;
                carry = 1;
            }
            else if(ibt[i]==1 && iibt[i] == 1 && carry == 0) {
                res[i] = 0;
                carry = 1;
            }
            else if(ibt[i]==0 && iibt[i]==0 && carry == 1){
                res[i] = 1;
                carry =0;
            }
            else if(ibt[i]==0 && iibt[i]==0 && carry == 0) {
                res[i] = 0;
                carry = 0;
            }
            else{
                
                if(carry == 0){
                    res[i] = 1;
                    carry=0;
                }
                else {
                    res[i] = 0;
                    carry = 1;
                }
            }
        }
        string sres =res.to_string();
        int t;
        for(int i=0;i<sres.size();i++) {
            if(sres[i]!='0'){
                t = i;
                break;
            }
        }
        string s(sres.begin()+t,sres.end());
        
        return s;
    }
};
