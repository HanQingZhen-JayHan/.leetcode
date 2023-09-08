/*
 * @lc app=leetcode id=264 lang=cpp
 *
 * [264] Ugly Number II
 *
 * https://leetcode.com/problems/ugly-number-ii/description/
 *
 * algorithms
 * Medium (45.34%)
 * Likes:    5660
 * Dislikes: 278
 * Total Accepted:    318K
 * Total Submissions: 688.4K
 * Testcase Example:  '10'
 *
 * An ugly number is a positive integer whose prime factors are limited to 2,
 * 3, and 5.
 *
 * Given an integer n, return the n^th ugly number.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 10
 * Output: 12
 * Explanation: [1, 2, 3, 4, 5, 6, 8, 9, 10, 12] is the sequence of the first
 * 10 ugly numbers.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: 1
 * Explanation: 1 has no prime factors, therefore all of its prime factors are
 * limited to 2, 3, and 5.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 1690
 *
 *
 */

// @lc code=start
#include "BaseSolution.h"
#include <queue>
#include <vector>
class Solution : BaseSolution {
public:
    int nthUglyNumber(int n) {}
    int setSolution(int n) {
        set<int> collection;
        collection.insert(1);
        int ugly = 1;
        for(int i = 0; i < n; ++i) {
            ugly = *collection.begin();
            collection.erase(ugly);
            collection.insert(ugly * 2);
            collection.insert(ugly * 3);
            collection.insert(ugly * 5);
        }
        return ugly;
    }

    int dpSolution(int n) {
        vector<int> v;
        v.push_back(1);
        int x = 0, y = 0, z = 0;
        for(int i = 1; i < n; i++) {
            v.push_back(min(v[x] * 2, min(v[y] * 3, v[z] * 5)));
            if(v.back() == v[x] * 2) {
                x++;
            }
            if(v.back() == v[y] * 3) {
                y++;
            }
            if(v.back() == v[z] * 5) {
                z++;
            }
        }
        return v.back();
    }
};
// @lc code=end
