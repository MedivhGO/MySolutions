/*
 * [204] Count Primes
 *
 * https://leetcode.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (26.65%)
 * Total Accepted:    138.9K
 * Total Submissions: 521.2K
 * Testcase Example:  '0'
 *
 * Description:
 * Count the number of prime numbers less than a non-negative number, n.
 * 
 * Credits:Special thanks to @mithmatt for adding this problem and creating all
 * test cases.
 */
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> prime(n,true);
        prime[0] = false;
        prime[1] = false;
        for (int i = 0;i < sqrt(n);++i) {
            if (prime[i]) {
                for (int j = i*i; j < n;j+=i) {
                    prime[j] = false;
                }
            }
        }
        
        return count(prime.begin(),prime.end(),true);
    }
};
