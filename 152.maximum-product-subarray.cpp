/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 *
 * https://leetcode.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (34.59%)
 * Likes:    16737
 * Dislikes: 513
 * Total Accepted:    1M
 * Total Submissions: 3M
 * Testcase Example:  '[2,3,-2,4]'
 *
 * Given an integer array nums, find a subarray that has the largest product,
 * and return the product.
 *
 * The test cases are generated so that the answer will fit in a 32-bit
 * integer.
 *
 *
 * Example 1:
 *
 *
 * Input: nums = [2,3,-2,4]
 * Output: 6
 * Explanation: [2,3] has the largest product 6.
 *
 *
 * Example 2:
 *
 *
 * Input: nums = [-2,0,-1]
 * Output: 0
 * Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= nums.length <= 2 * 10^4
 * -10 <= nums[i] <= 10
 * The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit
 * integer.
 *
 *
 */

// @lc code=start
#include "BaseSolution.h"
#include "PrintTools.h"
#include <algorithm>
#include <cstdint>
#include <vector>
class Solution152 : public BaseSolution {
public:
    void test() {
        vector<int> nums{ 2, 3, -2, 4 };
        printOutput(maxProduct(nums));
    }

public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int prefix = 1, suffix = 1;
        int res = INT32_MIN, res1 = INT32_MIN, res2 = INT32_MIN;
        for(int i = 0; i < len; ++i) {
            prefix *= nums[i];
            suffix *= nums[len -1- i];
            res1 = max(res1, prefix);
            res2 = max(res2, suffix);

            if(prefix == 0) {
                prefix = 1;
            }
            if(suffix == 0) {
                suffix = 1;
            }
        }
        res = max(res1, res2);
        return res;
    }
};
// @lc code=end
