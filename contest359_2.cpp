#pragma once

#include "BaseSolution.h"
#include "PrintTools.h"
#include <unordered_set>
class Contest359_2 : public BaseSolution {
public:
    void test() {
        string data = "str";
        printInput(data);
        // printOutput();
        printOutput(minimumSum(5, 4));
        printOutput(minimumSum(2, 6));
    }
    int minimumSum(int n, int k) {
        int i = 1;
        int sum = 0;
        unordered_set<int> data;
        while(n > 0) {
            if(data.find(i) == data.end()) {
                sum += i;
                data.insert(k - i);
                --n;
            }
            ++i;

        }
        return sum;
    }
};
