#pragma once

#include <iostream>
#include <string>
#include <vector>
using namespace std;
void print(const vector<int> &v) {
  cout << "[";
  int size = v.size();
  for (int i = 0; i < size; ++i) {
    cout << v[i] << ((i == size - 1) ? "" : ", ");
  }
  cout << "]" << endl;
}
void printOutput(const vector<int> &v) {
  cout << "Output: ";
  print(v);
}
void printInput(const vector<int> &v) {
  cout << "Input: ";
  print(v);
}

void printInput(const int d) { cout << "Input: " << d << endl; }
void printOutput(const int d) { cout << "Output: " << d << endl; }

void print(const string &str) { cout << str << endl; }