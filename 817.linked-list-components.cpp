/*
 * @lc app=leetcode id=817 lang=cpp
 *
 * [817] Linked List Components
 *
 * https://leetcode.com/problems/linked-list-components/description/
 *
 * algorithms
 * Medium (58.07%)
 * Likes:    955
 * Dislikes: 2112
 * Total Accepted:    83.6K
 * Total Submissions: 145.8K
 * Testcase Example:  '[0,1,2,3]\n[0,1,3]'
 *
 * You are given the head of a linked list containing unique integer values and
 * an integer array nums that is a subset of the linked list values.
 *
 * Return the number of connected components in nums where two values are
 * connected if they appear consecutively in the linked list.
 *
 *
 * Example 1:
 *
 *
 * Input: head = [0,1,2,3], nums = [0,1,3]
 * Output: 2
 * Explanation: 0 and 1 are connected, so [0, 1] and [3] are the two connected
 * components.
 *
 *
 * Example 2:
 *
 *
 * Input: head = [0,1,2,3,4], nums = [0,3,1,4]
 * Output: 2
 * Explanation: 0 and 1 are connected, 3 and 4 are connected, so [0, 1] and [3,
 * 4] are the two connected components.
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the linked list is n.
 * 1 <= n <= 10^4
 * 0 <= Node.val < n
 * All the values Node.val are unique.
 * 1 <= nums.length <= n
 * 0 <= nums[i] < n
 * All the values of nums are unique.
 *
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include "BaseSolution.h"
#include <unordered_set>
class Solution817 : BaseSolution {
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };

public:
    void test() {}

public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_set<int> data(nums.begin(), nums.end());
        int res = 0;
        bool flag = false;
        while(head != nullptr) {
            if(data.find(head->val) != data.end()) {
                flag = true;
            } else if(flag) {
                flag = false;
                res++;
            }
            head = head->next;
        }
        if(flag) {
            res++;
        }
        return res;
    }
};
// @lc code=end
