/*
 * [412] Fizz Buzz
 *
 * https://leetcode.com/problems/fizz-buzz/description/
 *
 * algorithms
 * Easy (58.24%)
 * Total Accepted:    97.3K
 * Total Submissions: 167.1K
 * Testcase Example:  '1'
 *
 * Write a program that outputs the string representation of numbers from 1 to
 * n.
 * 
 * But for multiples of three it should output “Fizz” instead of the number and
 * for the multiples of five output “Buzz”. For numbers which are multiples of
 * both three and five output “FizzBuzz”.
 * 
 * Example:
 * 
 * n = 15,
 * 
 * Return:
 * [
 * ⁠   "1",
 * ⁠   "2",
 * ⁠   "Fizz",
 * ⁠   "4",
 * ⁠   "Buzz",
 * ⁠   "Fizz",
 * ⁠   "7",
 * ⁠   "8",
 * ⁠   "Fizz",
 * ⁠   "Buzz",
 * ⁠   "11",
 * ⁠   "Fizz",
 * ⁠   "13",
 * ⁠   "14",
 * ⁠   "FizzBuzz"
 * ]
 * 
 * 
 */
class Solution {
public:
    
    vector<string> fizzBuzz(int n) {
        string s1 = "Fizz";
        string s2 = "Buzz";
        string s3 = "FizzBuzz";
        vector<string> svec;
        for(int i=1;i<=n;i++)
        {
            if(i%3==0 && i%5==0)
                svec.push_back(s3);
            else if(i%3 == 0)
                svec.push_back(s1);
            else if(i%5 == 0)
                svec.push_back(s2);
            else{
              stringstream ss;
              ss<<i;
              string sss;
              ss>>sss;
              svec.push_back(sss);
            }
                
                
        }
        return svec;
    }
};
