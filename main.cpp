#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "PrintTools.h"
#include "Data.h"
#include "1.two-sum.cpp"

using namespace std;
int main(int, char**){

  print("Hello, from LeetCode!");
  Solution s;
  Data data;
  printInput(data.vi);
  printInput(data.target);
  printOutput(s.twoSum(data.vi, data.target));

}
