#pragma once

#include <string>
#include <vector>
using namespace std;
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Data {
public:
  vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9};
  int target = 6;
  ListNode *buildListNode(const vector<int> &v) {
    ListNode *root = new ListNode();
    ListNode *n = root;
    for (auto i : v) {
      n = buildListNode(n, i);
    }
    return root->next;
  }

private:
  ListNode *buildListNode(ListNode *node, int value) {
    ListNode *n = new ListNode(value);
    node->next = n;
    return n;
  }
};