/*
 * [405] Convert a Number to Hexadecimal
 *
 * https://leetcode.com/problems/convert-a-number-to-hexadecimal/description/
 *
 * algorithms
 * Easy (41.06%)
 * Total Accepted:    30.7K
 * Total Submissions: 74.7K
 * Testcase Example:  '26'
 *
 * 
 * Given an integer, write an algorithm to convert it to hexadecimal. For
 * negative integer, two’s complement method is used.
 * 
 * 
 * Note:
 * 
 * All letters in hexadecimal (a-f) must be in lowercase.
 * The hexadecimal string must not contain extra leading 0s. If the number is
 * zero, it is represented by a single zero character '0'; otherwise, the first
 * character in the hexadecimal string will not be the zero character.
 * The given number is guaranteed to fit within the range of a 32-bit signed
 * integer.
 * You must not use any method provided by the library which converts/formats
 * the number to hex directly.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 26
 * 
 * Output:
 * "1a"
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * -1
 * 
 * Output:
 * "ffffffff"
 * 
 * 
 */
class Solution {
public:
    char covertToChar(int x) {
        unordered_map<int,char> mapping;
        for(int i=0;i<=9;i++) {
            mapping[i] = i+'0';
        }
        for(int i=10;i<=15;i++){
            mapping[i] = i-10+'a';
        }
        return mapping[x];
    }
    string bitToHex(bitset<32> bis) {
        stack<char> stk;
        for(int i=0;i<32;i=i+4){
            int j=i;
            int count=4;
            int sum=0;
            int c=0;
            while(count!=0) {
                sum += bis[j+c]*pow(2,c);
                c++;
                count--;
            }
            char cc = covertToChar(sum);
            stk.push(cc);
        }
        while(stk.top()== '0'){
            stk.pop();
        }
        vector<char> cvec;
        while(!stk.empty()) {
            cvec.push_back(stk.top());
            stk.pop();
        }
        string s = string(cvec.begin(),cvec.end());
        return s;
    }
    string toHex(int num) {
        if(num==0)
            return  "0";
        if(num<0)
            num+=4294967296;
        bitset<32> bi(num);
        string s;
        s = bitToHex(bi);
        return s;
    }
};
