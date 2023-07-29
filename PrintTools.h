#pragma once

#include "Data.h"
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
void print(const string& str) { cout << str << endl; }
void print(const unordered_set<string>& us) {
    cout << "unordered_set:[" << endl;
    int size = us.size();
    for(auto s : us) {
        print(s);
    }

    cout << "]" << endl;
}
void print(const vector<string>& v) {
    cout << "[";
    int size = v.size();
    for(int i = 0; i < size; ++i) {
        cout << v[i] << ((i == size - 1) ? "" : ", ");
    }
    cout << "]" << endl;
}
void print(const vector<int>& v) {
    cout << "[";
    int size = v.size();
    for(int i = 0; i < size; ++i) {
        cout << v[i] << ((i == size - 1) ? "" : ", ");
    }
    cout << "]" << endl;
}
void print(unordered_map<string, vector<string>> wordMap) {
    for(auto m : wordMap) {
        cout << m.first << " : ";
        print(m.second);
    }
}
void printOutput(const vector<int>& v) {
    cout << "Output: ";
    print(v);
}
void printInput(const vector<int>& v) {
    cout << "Input: ";
    print(v);
}
void printOutput(const vector<vector<int>>& vv) {
    cout << "Output: ";
    for(auto v : vv) {
        print(v);
    }
}
void printOutput(const vector<vector<string>>& vv) {
    cout << "Output: ";
    for(auto v : vv) {
        print(v);
    }
}

void printInput(const int d) { cout << "Input: " << d << endl; }
void printOutput(const int d) { cout << "Output: " << d << endl; }
void printInput(const string& str) { cout << "Input: " << str << endl; }
void printOutput(const string& str) { cout << "Output: " << str << endl; }

void printNode(ListNode* node) {
    while(node != nullptr) {
        cout << node->val << (node->next != nullptr ? "->" : "");
        node = node->next;
    }
    cout << endl;
}