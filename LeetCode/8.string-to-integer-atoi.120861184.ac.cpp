/*
 * [8] String to Integer (atoi)
 *
 * https://leetcode.com/problems/string-to-integer-atoi/description/
 *
 * algorithms
 * Medium (13.93%)
 * Total Accepted:    204.6K
 * Total Submissions: 1.5M
 * Testcase Example:  '""'
 *
 * Implement atoi to convert a string to an integer.
 * 
 * Hint: Carefully consider all possible input cases. If you want a challenge,
 * please do not see below and ask yourself what are the possible input
 * cases.
 * 
 * 
 * Notes: 
 * It is intended for this problem to be specified vaguely (ie, no given input
 * specs). You are responsible to gather all the input requirements up
 * front. 
 * 
 * 
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your
 * function signature accepts a const char * argument, please click the reload
 * button  to reset your code definition.
 * 
 * 
 * spoilers alert... click to show requirements for atoi.
 * 
 * Requirements for atoi:
 * 
 * The function first discards as many whitespace characters as necessary until
 * the first non-whitespace character is found. Then, starting from this
 * character, takes an optional initial plus or minus sign followed by as many
 * numerical digits as possible, and interprets them as a numerical value.
 * 
 * The string can contain additional characters after those that form the
 * integral number, which are ignored and have no effect on the behavior of
 * this function.
 * 
 * If the first sequence of non-whitespace characters in str is not a valid
 * integral number, or if no such sequence exists because either str is empty
 * or it contains only whitespace characters, no conversion is performed.
 * 
 * If no valid conversion could be performed, a zero value is returned. If the
 * correct value is out of the range of representable values, INT_MAX
 * (2147483647) or INT_MIN (-2147483648) is returned.
 * 
 * 
 */
class Solution {
public:
    int getSum(string str,int flag) {
        int ans = 0;
        for (int i =0 ;i < str.size() && isdigit(str[i]) ;i++) {
            if ( ans > (INT_MAX - (str[i] - '0'))/10 )
                return flag == 1 ? INT_MAX : INT_MIN;
            ans*=10;
            ans+=str[i]-'0';
        }
        if(flag ==  1) return ans;
        else return -ans;
    
    }
    int myAtoi(string str) {
        int ans = 0;
        int flag = 1;
        if (str.empty()) return ans;
        int len = str.size();
        vector<char> res;
        int i = 0;
        for ( i = 0;i<len;i++) {
            if (isspace(str[i])) continue;
            else break;
        }
        if (str[i] == '+') {
            flag  = 1;
            i++;
            if (ispunct(str[i]))
                return ans;
            else {
                string t(str.begin()+i,str.end());
                return  getSum(t,flag);
            }
        }
        else if (str[i] == '-') {
            flag = 0;
            i++;
            if (ispunct(str[i]) )
                return ans;
            else {
                string t(str.begin()+i,str.end());
                return  getSum(t,flag);
            }
        }
        else if (isdigit(str[i])) {
            string t(str.begin()+i,str.end());
            return  getSum(t,flag);
        } else {
            return ans;
        }
    }
    
};

