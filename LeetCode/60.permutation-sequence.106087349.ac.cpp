/*
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (29.15%)
 * Total Accepted:    95.3K
 * Total Submissions: 327K
 * Testcase Example:  '1\n1'
 *
 * The set [1,2,3,…,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order,
 * We get the following sequence (ie, for n = 3):
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * 
 * Given n and k, return the kth permutation sequence.
 * 
 * Note: Given n will be between 1 and 9 inclusive.
 */
class Solution {
public:
    string getPermutation(int n, int k) {
        string s(n,'0');
        for (int i=0;i<n;++i)
            s[i] = i+'1';
        for (int i=0;i<k-1;++i)
            next_permutation(s.begin(),s.end());
            
        return s;
    }
private:
    template<typename BidiIt>
    bool next_permutation(BidiIt first,BidiIt last) {
        const auto rfirst = reverse_iterator<BidiIt>(last);
        const auto rlast = reverse_iterator<BidiIt>(first);
        
        auto pivot = next(rfirst);
        
        while (pivot != rlast && *pivot >= *prev(pivot))
            ++pivot;
        
        if (pivot == rlast) {
            reverse(rfirst,rlast);
            return false;
        }
        
        auto change = find_if(rfirst,pivot,bind1st(less<int>(),*pivot));
        
        swap(*change,*pivot);
        reverse(rfirst,pivot);
        
        return true;
    }
};
