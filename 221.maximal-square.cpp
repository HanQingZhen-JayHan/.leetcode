/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (43.55%)
 * Likes:    9461
 * Dislikes: 198
 * Total Accepted:    612.5K
 * Total Submissions: 1.3M
 * Testcase Example: '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given an m x n binary matrix filled with 0's and 1's, find the largest
 * square containing only 1's and return its area.
 *
 *
 * Example 1:
 *
 *
 * Input: matrix =
 * [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
 * Output: 4
 *
 *
 * Example 2:
 *
 *
 * Input: matrix = [["0","1"],["1","0"]]
 * Output: 1
 *
 *
 * Example 3:
 *
 *
 * Input: matrix = [["0"]]
 * Output: 0
 *
 *
 *
 * Constraints:
 *
 *
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= m, n <= 300
 * matrix[i][j] is '0' or '1'.
 *
 *
 */

// @lc code=start
#include "BaseSolution.h"
#include <vector>
class Solution221 : BaseSolution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[m - 1].size();
        int ms=0;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for(int r = 1; r <= m; ++r) {
            for(int c = 1; c <= n; ++c) {
                if(matrix[r-1][c-1]=='1'){
                    dp[r][c] =1+ min(dp[r-1][c],min(dp[r][c-1],dp[r-1][c-1]));
                    ms = max(ms,dp[r][c]);
                }
            }
        }
        return ms*ms;
    }
};
// @lc code=end
