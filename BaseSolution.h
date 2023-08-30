#pragma once
#include "Data.h"
#include "PrintTools.h"
#include <algorithm>
#include <iterator>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right)
    : val(x), left(left), right(right) {}
};
class BaseSolution {
protected:
    Data data;
    virtual void test() {}
};