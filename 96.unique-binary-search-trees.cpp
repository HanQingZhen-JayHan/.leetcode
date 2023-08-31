/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (58.42%)
 * Likes:    9833
 * Dislikes: 378
 * Total Accepted:    603.7K
 * Total Submissions: 1M
 * Testcase Example:  '3'
 *
 * Given an integer n, return the number of structurally unique BST's (binary
 * search trees) which has exactly n nodes of unique values from 1 to n.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3
 * Output: 5
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: 1
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 19
 *
 *
 */

// @lc code=start
#include "BaseSolution.h"
#include <vector>
class Solution : BaseSolution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        for(int i = 2; i <= n; ++i) {
            int cnt = 0;
            for(int j = 1; j <= i; ++j) {
                int l = dp[j - 1];
                int r = dp[i - j];
                cnt += l * r;
            }
            dp[i] = cnt;
        }
        return dp[n];
    }
};
// @lc code=end
