/*
 * [295] Find Median from Data Stream
 *
 * https://leetcode.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (28.50%)
 * Total Accepted:    53K
 * Total Submissions: 185.9K
 * Testcase Example:  '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n[[],[1],[2],[],[3],[]]'
 *
 * Median is the middle value in an ordered integer list. If the size of the
 * list is even, there is no middle value. So the median is the mean of the two
 * middle value.
 * Examples: 
 * [2,3,4] , the median is 3
 * [2,3], the median is (2 + 3) / 2 = 2.5 
 * 
 * 
 * Design a data structure that supports the following two operations:
 * 
 * 
 * void addNum(int num) - Add a integer number from the data stream to the data
 * structure.
 * double findMedian() - Return the median of all elements so far.
 * 
 * 
 * 
 * For example:
 * 
 * addNum(1)
 * addNum(2)
 * findMedian() -> 1.5
 * addNum(3) 
 * findMedian() -> 2
 * 
 * 
 * Credits:Special thanks to @Louis1992 for adding this problem and creating
 * all test cases.
 */
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int count = max_heap.size() + min_heap.size();
        if (count % 2 == 0) {
            max_heap.push(num);
            min_heap.push(max_heap.top());
            max_heap.pop();
        } else {
            min_heap.push(num);
            max_heap.push(min_heap.top());
            min_heap.pop();
            
        }
    }
    
    double findMedian() {
        int total = max_heap.size() + min_heap.size();
        double ans = -9999;
        if (total <= 0) return ans;
        if (total % 2 != 0) {
            ans = min_heap.top();
        } else  {
            int sum = min_heap.top() + max_heap.top();
            ans = sum/2.0;
        }
        return ans;
        
    }
private:
    priority_queue<int,vector<int>,less<int>> max_heap;
    priority_queue<int,vector<int>,greater<int>> min_heap;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
