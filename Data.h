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
  vector<int> vi{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int target = 6;
};