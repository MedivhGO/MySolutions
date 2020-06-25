/*
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (31.33%)
 * Total Accepted:    170.2K
 * Total Submissions: 543.4K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * 
 * For example,
 * Given [1,3],[2,6],[8,10],[15,18],
 * return [1,6],[8,10],[15,18].
 * 
 */
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> ans;
        if (intervals.empty()) return ans;
        sort(intervals.begin(),intervals.end(),[](Interval a,Interval b) {return a.start < b.start || a.start == b.start && a.end < b.end ;});
        
        Interval cur = intervals[0];
        ans.push_back(cur);
        for (int i = 1; i<intervals.size();i++) {
             if (ans.back().end < intervals[i].start) ans.push_back(intervals[i]);
             else 
                 ans.back().end = max(ans.back().end,intervals[i].end);
        }
        
        return ans;
    }
};
