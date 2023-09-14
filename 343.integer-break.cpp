/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (54.26%)
 * Likes:    3891
 * Dislikes: 371
 * Total Accepted:    243.9K
 * Total Submissions: 430.4K
 * Testcase Example:  '2'
 *
 * Given an integer n, break it into the sum of k positive integers, where k >=
 * 2, and maximize the product of those integers.
 *
 * Return the maximum product you can get.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.
 *
 *
 * Example 2:
 *
 *
 * Input: n = 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 *
 *
 *
 * Constraints:
 *
 *
 * 2 <= n <= 58
 *
 *
 */

// @lc code=start
#include "BaseSolution.h"
#include "PrintTools.h"
#include <vector>
class Solution343 : BaseSolution {

public:
    void test() {
        for(int i = 2; i < 20; i++) {
            printOutput(integerBreak(i));
        }
    }
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        dp[3] = 2;
        for(int i = 4; i <= n; i++) {
            for(int j = 1; j < i; j++) {
                int m1 = max(j * dp[i - j], dp[j] * dp[i - j]);
                int m2 = max(j * (i - j), dp[i]);
                dp[i] = max(m1, m2);
            }
        }
        return dp[n];
    }
};
// @lc code=end
