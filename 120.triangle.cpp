/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 *
 * https://leetcode.com/problems/triangle/description/
 *
 * algorithms
 * Medium (51.01%)
 * Likes:    8828
 * Dislikes: 508
 * Total Accepted:    643.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * Given a triangle array, return the minimum path sum from top to bottom.
 *
 * For each step, you may move to an adjacent number of the row below. More
 * formally, if you are on index i on the current row, you may move to either
 * index i or index i + 1 on the next row.
 *
 *
 * Example 1:
 *
 *
 * Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
 * Output: 11
 * Explanation: The triangle looks like:
 * ⁠  2
 * ⁠ 3 4
 * ⁠6 5 7
 * 4 1 8 3
 * The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined
 * above).
 *
 *
 * Example 2:
 *
 *
 * Input: triangle = [[-10]]
 * Output: -10
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= triangle.length <= 200
 * triangle[0].length == 1
 * triangle[i].length == triangle[i - 1].length + 1
 * -10^4 <= triangle[i][j] <= 10^4
 *
 *
 *
 * Follow up: Could you do this using only O(n) extra space, where n is the
 * total number of rows in the triangle?
 */

// @lc code=start
#include "BaseSolution.h"
#include "PrintTools.h"
#include <algorithm>
#include <vector>
class Solution120 : BaseSolution {
public:
    void test() {
        vector<vector<int>> data{ { 2 }, { 3, 4 }, { 6, 5, 7 }, { 4, 1, 8, 3 } };
        printOutput(minimumTotal(data));
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);
        //bottom to top
        for(int r = n-1; r >=0; --r) {
            for(int i=0;i<triangle[r].size();i++){
                if(r==n-1){
                    dp[i] = triangle[r][i];
                }else{
                    dp[i] = triangle[r][i]+min(dp[i],dp[i+1]);
                }
            }   
        }
        return dp[0];
    }
    //top to bottom
    int dp(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);
        dp[0] = triangle[0][0];
        int ans = dp[0];
        for(int r = 1; r < n; ++r) {
            ans = dp[0] + triangle[r][0];
            for(int i = triangle[r].size() - 1; i > 0; --i) {
                if(i < triangle[r].size() - 1) {
                    dp[i] = triangle[r][i] + min(dp[i - 1], dp[i]);
                } else {
                    dp[i] = triangle[r][i] + dp[i - 1];
                }
                ans = min(ans, dp[i]);
            }
            dp[0] += triangle[r][0];
            ans = min(ans, dp[0]);
        }
        return ans;
    }
};
// @lc code=end
