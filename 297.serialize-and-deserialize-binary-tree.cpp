/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
 *
 * https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
 *
 * algorithms
 * Hard (53.91%)
 * Likes:    9348
 * Dislikes: 342
 * Total Accepted:    769.8K
 * Total Submissions: 1.4M
 * Testcase Example:  '[1,2,3,null,null,4,5]'
 *
 * Serialization is the process of converting a data structure or object into a
 * sequence of bits so that it can be stored in a file or memory buffer, or
 * transmitted across a network connection link to be reconstructed later in
 * the same or another computer environment.
 *
 * Design an algorithm to serialize and deserialize a binary tree. There is no
 * restriction on how your serialization/deserialization algorithm should work.
 * You just need to ensure that a binary tree can be serialized to a string and
 * this string can be deserialized to the original tree structure.
 *
 * Clarification: The input/output format is the same as how LeetCode
 * serializes a binary tree. You do not necessarily need to follow this format,
 * so please be creative and come up with different approaches yourself.
 *
 *
 * Example 1:
 *
 *
 * Input: root = [1,2,3,null,null,4,5]
 * Output: [1,2,3,null,null,4,5]
 *
 *
 * Example 2:
 *
 *
 * Input: root = []
 * Output: []
 *
 *
 *
 * Constraints:
 *
 *
 * The number of nodes in the tree is in the range [0, 10^4].
 * -1000 <= Node.val <= 1000
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "BaseSolution.h"
#include "PrintTools.h"
#include <queue>
#include <string>
#include <vector>
class Codec : public BaseSolution {
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

public:
    void test() {
        string data = "1,2,3,null,null,4,5";
        printInput(data);
        printOutput(serialize(deserialize(data)));
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root == nullptr) {
            return "";
        }
        vector<string> tree;
        bfs(root, tree);
        for(auto it = tree.rbegin(); it != tree.rend() && *it == "null"; ++it) {
            tree.pop_back();
        }
        string res = "";
        for(auto it = tree.begin(); it != tree.end(); ++it) {
            res += *it + ",";
        }
        return res.substr(0, res.size() - 1);
    }
    void bfs(TreeNode* root, vector<string>& tree) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int s = q.size();
            while(s > 0) {
                if(q.front() == nullptr) {
                    tree.push_back("null");
                } else {
                    tree.push_back(to_string(q.front()->val));
                    q.push(q.front()->left);
                    q.push(q.front()->right);
                }
                q.pop();
                --s;
            }
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) {
            return nullptr;
        }
        vector<string> tree;
        int s = 0;
        int e = data.find(',', s);
        while(e > 0) {
            tree.push_back(data.substr(s, e - s));
            s = e + 1;
            e = data.find(',', s);
        }
        tree.push_back(data.substr(s));
        if(tree[0] == "null") {
            return nullptr;
        }
        int i = 0;
        TreeNode* root = new TreeNode(stoi(tree[i++]));
        queue<TreeNode*> q;
        q.push(root);
        int size = tree.size();
        while(i < size) {
            string sub = tree[i++];
            if(sub != "null") {
                q.front()->left = new TreeNode(stoi(sub));
                q.push(q.front()->left);
            }
            if(i >= size) {
                break;
            }
            sub = tree[i++];
            if(sub != "null") {
                q.front()->right = new TreeNode(stoi(sub));
                q.push(q.front()->right);
            }
            q.pop();
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end
