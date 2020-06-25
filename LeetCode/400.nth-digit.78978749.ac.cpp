/*
 * [400] Nth Digit
 *
 * https://leetcode.com/problems/nth-digit/description/
 *
 * algorithms
 * Easy (30.13%)
 * Total Accepted:    30.4K
 * Total Submissions: 100.9K
 * Testcase Example:  '3'
 *
 * Find the nth digit of the infinite integer sequence 1, 2, 3, 4, 5, 6, 7, 8,
 * 9, 10, 11, ... 
 * 
 * Note:
 * n is positive and will fit within the range of a 32-bit signed integer (n <
 * 231).
 * 
 * 
 * Example 1:
 * 
 * Input:
 * 3
 * 
 * Output:
 * 3
 * 
 * 
 * 
 * Example 2:
 * 
 * Input:
 * 11
 * 
 * Output:
 * 0
 * 
 * Explanation:
 * The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a
 * 0, which is part of the number 10.
 * 
 * 
 */
class Solution {
public:
    int findNthDigit(int n) {
        long num =0,start=1,i=1;
        if(n<10) return n;
        
        while(n>num+start*9*i){
            num+=start*9*i;
            i++;
            start*=10;
        }
        
        int target=n-num-1;
        num = start+target/i;
        int base = 1;
        for(int j=i-1;j>target%i;j--) num/=10;
        return num%10;
    }
};
