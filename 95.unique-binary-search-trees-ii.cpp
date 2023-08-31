/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (49.71%)
 * Likes:    7215
 * Dislikes: 478
 * Total Accepted:    414.5K
 * Total Submissions: 738.4K
 * Testcase Example:  '3'
 *
 * Given an integer n, return all the structurally unique BST's (binary search
 * trees), which has exactly n nodes of unique values from 1 to n. Return the
 * answer in any order.
 *
 *
 * Example 1:
 *
 *
 * Input: n = 3
 * Output:
 * [[1,null,2,null,3],[1,null,3,2],[2,1,3],[3,1,null,null,2],[3,2,null,1]]
 *
 *
 * Example 2:
 *
 *
 * Input: n = 1
 * Output: [[1]]
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= n <= 8
 *
 *
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include "BaseSolution.h"
#include <vector>
class Solution95 : BaseSolution {
public:
    void test() { vector<TreeNode*> res = generateTrees(3); }
    vector<TreeNode*> generateTrees(int n) { return dfs(1, n); }


    vector<TreeNode*> dp(int n) {
        vector<vector<TreeNode*>> dp(n+1, vector<TreeNode*>());
        dp[0].push_back(nullptr);
        for(int i = 1; i <= n; ++i) {
            vector<TreeNode*> v;
            for(int j = 1; j <= i; ++j) {
                vector<TreeNode*> ls = dp[j - 1];
                vector<TreeNode*> rs = dp[i - j];
                for(auto l : ls) {
                    for(auto r : rs) {
                        TreeNode* root = new TreeNode(j, l, clone(r,j));
                        v.push_back(root);
                    }
                }
            }
            dp[i] = v;
        }
        return dp[n];
    }
    TreeNode* clone(TreeNode* r, int offset) {
        if(r == nullptr) {
            return nullptr;
        }
        TreeNode* root = new TreeNode(r->val + offset);
        root->left = clone(r->left, offset);
        root->right = clone(r->right, offset);
        return root;
    }
    //[start, index-1]: left
    // index: root
    // [index+1, end]: right
    vector<TreeNode*> dfs(int start, int end) {
        vector<TreeNode*> res;
        if(start > end) {
            res.push_back(nullptr);
            return res;
        }
        if(start == end) {
            res.push_back(new TreeNode(start));
            return res;
        }
        for(int i = start; i <= end; ++i) {
            vector<TreeNode*> l = dfs(start, i - 1);
            vector<TreeNode*> r = dfs(i + 1, end);

            for(auto itl : l) {
                for(auto itr : r) {
                    TreeNode* root = new TreeNode(i, itl, itr);
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};
// @lc code=end
