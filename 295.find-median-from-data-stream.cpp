/*
 * @lc app=leetcode id=295 lang=cpp
 *
 * [295] Find Median from Data Stream
 *
 * https://leetcode.com/problems/find-median-from-data-stream/description/
 *
 * algorithms
 * Hard (50.42%)
 * Likes:    10893
 * Dislikes: 211
 * Total Accepted:    662.9K
 * Total Submissions: 1.3M
 * Testcase Example: '["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]\n' +
  '[[],[1],[2],[],[3],[]]'
 *
 * The median is the middle value in an ordered integer list. If the size of
 * the list is even, there is no middle value, and the median is the mean of
 * the two middle values.
 *
 *
 * For example, for arr = [2,3,4], the median is 3.
 * For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
 *
 *
 * Implement the MedianFinder class:
 *
 *
 * MedianFinder() initializes the MedianFinder object.
 * void addNum(int num) adds the integer num from the data stream to the data
 * structure.
 * double findMedian() returns the median of all elements so far. Answers
 * within 10^-5 of the actual answer will be accepted.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
 * [[], [1], [2], [], [3], []]
 * Output
 * [null, null, null, 1.5, null, 2.0]
 *
 * Explanation
 * MedianFinder medianFinder = new MedianFinder();
 * medianFinder.addNum(1);    // arr = [1]
 * medianFinder.addNum(2);    // arr = [1, 2]
 * medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
 * medianFinder.addNum(3);    // arr[1, 2, 3]
 * medianFinder.findMedian(); // return 2.0
 *
 *
 *
 * Constraints:
 *
 *
 * -10^5 <= num <= 10^5
 * There will be at least one element in the data structure before calling
 * findMedian.
 * At most 5 * 10^4 calls will be made to addNum and findMedian.
 *
 *
 *
 * Follow up:
 *
 *
 * If all integer numbers from the stream are in the range [0, 100], how would
 * you optimize your solution?
 * If 99% of all integer numbers from the stream are in the range [0, 100], how
 * would you optimize your solution?
 *
 *
 */

// @lc code=start
#include "BaseSolution.h"
#include "PrintTools.h"
#include <algorithm>
#include <functional>
#include <queue>
#include <string>
#include <vector>
class MedianFinder : BaseSolution {
public:
    void test() {
        addNum(1);
        addNum(3);
        printOutput(to_string(findMedian()));
        addNum(2);
        printOutput(to_string(findMedian()));
        addNum(1);
        printOutput(to_string(findMedian()));
        addNum(1);
        addNum(1);
        printOutput(to_string(findMedian()));
    }

private:
    //  \-----/
    //   \min/
    //    \ /
    //    / \ 
    //   /max\
    //  /-----\

    priority_queue<int, vector<int>, greater<int>> minHeap;
    priority_queue<int> maxHeap;
    int size = 0;

public:
    MedianFinder() {}

    void addNum(int num) {
        if(size % 2 == 0) {
            // even : max heap first
            if(minHeap.empty() || minHeap.top() >= num) {
                maxHeap.push(num);
            } else {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }

        } else {
            // odd : min heap first
            if(maxHeap.top() <= num) {
                minHeap.push(num);
            } else {

                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
        }
        ++size;
    }

    double findMedian() {
        if(size % 2 == 1) {
            return maxHeap.top();
        } else {
            return double(maxHeap.top()+ minHeap.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end
