/*
 * @lc app=leetcode id=357 lang=cpp
 *
 * [357] Count Numbers with Unique Digits
 *
 * https://leetcode.com/problems/count-numbers-with-unique-digits/description/
 *
 * algorithms
 * Medium (50.70%)
 * Likes:    1407
 * Dislikes: 1447
 * Total Accepted:    124.8K
 * Total Submissions: 238.7K
 * Testcase Example:  '2'
 *
 * Given an integer n, return the count of all numbers with unique digits, x,
 * where 0 <= x < 10^n.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 2
 * Output: 91
 * Explanation: The answer should be the total numbers in the range of 0 ≤ x <
 * 100, excluding 11,22,33,44,55,66,77,88,99
 *
 *
 * Example 2:
 *
 *
 * Input: n = 0
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 0 <= n <= 8
 *
 *
 */

// @lc code=start
#include "BaseSolution.h"
#include <vector>
class Solution : BaseSolution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n < 1) {
            return 1;
        }
        vector<int> dp(n + 1, 1);
        int uniques = 9;
        dp[1] = uniques + dp[0];

        for(int i = 2; i <= n; i++) {
            uniques *= (10 - (i-1));
            dp[i] = dp[i - 1] + uniques;
        }
        return dp[n];
    }
};
// @lc code=end
