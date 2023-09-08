/*
 * @lc app=leetcode id=279 lang=cpp
 *
 * [279] Perfect Squares
 *
 * https://leetcode.com/problems/perfect-squares/description/
 *
 * algorithms
 * Medium (51.92%)
 * Likes:    10017
 * Dislikes: 411
 * Total Accepted:    694.3K
 * Total Submissions: 1.3M
 * Testcase Example:  '12'
 *
 * Given an integer n, return the least number of perfect square numbers that
 * sum to n.
 *
 * A perfect square is an integer that is the square of an integer; in other
 * words, it is the product of some integer with itself. For example, 1, 4, 9,
 * and 16 are perfect squares while 3 and 11 are not.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 12
 * Output: 3
 * Explanation: 12 = 4 + 4 + 4.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 13
 * Output: 2
 * Explanation: 13 = 4 + 9.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 10^4
 *
 *
 */

// @lc code=start
#include "BaseSolution.h"
#include "PrintTools.h"
#include <unordered_map>
#include <vector>
class Solution279 : BaseSolution {
public:
    void test() { printOutput(numSquares(1)); }

public:
    int numSquares(int n) {
        if(n < 4) {
            return n;
        }
        vector<int> cache(n + 1, 0);
        cache[1] = 1;
        cache[2] = 2;
        cache[3] = 3;
        for(int i = 4; i <= n; i++) {
            int d = floor(sqrt(i));
            if(d * d == i) {
                cache[i] = 1;
            } else {
                int count = 1 + cache[i - 1];
                for(int j = d; j > 1; j--) {
                    count = min(count, cache[j * j] + cache[i - j * j]);
                }
                cache[i] = count;
            }
        }
        return cache[n];
    }
};
// @lc code=end
