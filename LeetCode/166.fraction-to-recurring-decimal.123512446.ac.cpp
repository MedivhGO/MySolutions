/*
 * [166] Fraction to Recurring Decimal
 *
 * https://leetcode.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (17.89%)
 * Total Accepted:    59.4K
 * Total Submissions: 332.2K
 * Testcase Example:  '1\n5'
 *
 * Given two integers representing the numerator and denominator of a fraction,
 * return the fraction in string format.
 * 
 * If the fractional part is repeating, enclose the repeating part in
 * parentheses.
 * 
 * For example,
 * 
 * Given numerator = 1, denominator = 2, return "0.5".
 * Given numerator = 2, denominator = 1, return "2".
 * Given numerator = 2, denominator = 3, return "0.(6)".
 * 
 * 
 * 
 * Credits:Special thanks to @Shangrila for adding this problem and creating
 * all test cases.
 */
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        //题目大意 给定分子分母返回他的小数形式，如果是循环小数，将循环结用括号扩起来。
        if (!numerator) return "0";
        string res;
        if (numerator < 0 ^ denominator < 0) res += '-'; //异或，分子分母的符号不同。
        long numer = numerator < 0 ? (long)numerator * (-1) : (long)numerator;
        long denom = denominator < 0 ? (long)denominator * (-1) : (long)denominator;
        long integral = numer / denom;
        res += to_string(integral);
        long rmd = numer % denom;
        if (!rmd) return res;
        res += '.';
        rmd *= 10;
        unordered_map<long, long> mp; 
        while (rmd) {
            long quotient = rmd / denom;
            if (mp.find(rmd) != mp.end()) { 
                res.insert(mp[rmd], 1, '(');
                res += ')';
                break;
            }
            mp[rmd] = res.size();
            res += to_string(quotient);
            rmd = (rmd % denom) * 10;
        }
        return res; 
    }
};
