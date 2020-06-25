/*
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (27.76%)
 * Total Accepted:    125.2K
 * Total Submissions: 451K
 * Testcase Example:  '"0"\n"0"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2.
 * 
 * Note:
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */
typedef vector<int> bigint;
bigint make_bigint(string const& repr) {
    bigint n;
    transform(repr.rbegin(),repr.rend(),back_inserter(n),[](char c){return c-'0';});
    return n;
}
string to_string(bigint const& n) {
    string str;
    transform(find_if(n.rbegin(),prev(n.rend()),[](char c){return c > '\0';}), //找到第一个非空数字
              n.rend(), back_inserter(str),[](char c) {return c + '0' ;}
             );
    return str;
    
}
bigint operator*(bigint const&x,bigint const& y) {
    bigint z(x.size()+y.size());
    for (size_t i = 0;i < x.size() ;i++) 
        for (size_t j = 0;j < y.size();j++) {
            z[i+j] += x[i] * y[j];
            z[i+j+1] += z[i+j]/10;
            z[i+j] %= 10;
        }
    return z;
}
class Solution {
public:
    string multiply(string num1, string num2) {
        return to_string(make_bigint(num1)*make_bigint(num2));
    }
};
