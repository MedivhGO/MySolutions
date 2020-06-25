/*
 * [278] First Bad Version
 *
 * https://leetcode.com/problems/first-bad-version/description/
 *
 * algorithms
 * Easy (25.93%)
 * Total Accepted:    127.5K
 * Total Submissions: 491.9K
 * Testcase Example:  '1 version\n1 is the first bad version.'
 *
 * 
 * You are a product manager and currently leading a team to develop a new
 * product. Unfortunately, the latest version of your product fails the quality
 * check. Since each version is developed based on the previous version, all
 * the versions after a bad version are also bad. 
 * 
 * 
 * 
 * Suppose you have n versions [1, 2, ..., n] and you want to find out the
 * first bad one, which causes all the following ones to be bad.
 * 
 * 
 * 
 * You are given an API bool isBadVersion(version) which will return whether
 * version is bad. Implement a function to find the first bad version. You
 * should minimize the number of calls to the API.
 * 
 * 
 * Credits:Special thanks to @jianchao.li.fighter for adding this problem and
 * creating all test cases.
 */
// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int left = 1;
        int right = n;
       
        while (left <= right) {
            int mid = left + (right-left)/2;
            if (isBadVersion(mid)) {
                if (isBadVersion(mid-1)==false)
                    return mid;
                else
                    right = mid-1;
            }
            else {
                left = mid+1;
            }
        }
    }
};
