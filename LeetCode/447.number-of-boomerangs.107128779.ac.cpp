/*
 * [447] Number of Boomerangs
 *
 * https://leetcode.com/problems/number-of-boomerangs/description/
 *
 * algorithms
 * Easy (45.99%)
 * Total Accepted:    31.3K
 * Total Submissions: 68K
 * Testcase Example:  '[[0,0],[1,0],[2,0]]'
 *
 * Given n points in the plane that are all pairwise distinct, a "boomerang" is
 * a tuple of points (i, j, k) such that the distance between i and j equals
 * the distance between i and k (the order of the tuple matters).
 * 
 * Find the number of boomerangs. You may assume that n will be at most 500 and
 * coordinates of points are all in the range [-10000, 10000] (inclusive).
 * 
 * Example:
 * 
 * Input:
 * [[0,0],[1,0],[2,0]]
 * 
 * Output:
 * 2
 * 
 * Explanation:
 * The two boomerangs are [[1,0],[0,0],[2,0]] and [[1,0],[2,0],[0,0]]
 * 
 * 
 */
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        if (points.empty())
            return 0;
        int ans = 0;
        for (int i=0;i<points.size();++i) {
            //创建一个hashmap 以两点之间的长度为键，值为一个计数器
            unordered_map<long,size_t> m;
            for (int j=0;j<points.size();++j) {
                if (i == j) continue;
                
                int dx = points[i].first - points[j].first;
                int dy = points[i].second - points[j].second;
                
                int len = dx*dx + dy*dy;
                m[len]++;
            }
            
            for (auto p : m) {
                if (p.second  > 1)
                 ans += p.second * (p.second - 1);
            }
            
        }
        return ans;
    }
};
