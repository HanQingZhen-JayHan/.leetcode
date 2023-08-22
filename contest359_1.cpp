#pragma once

#include "BaseSolution.h"
#include "PrintTools.h"
#include <vector>
class Contest359_1 : public BaseSolution {
public:
    void test() {
        string data = "str";
        printInput(data);
        // printOutput();
    }
    bool isAcronym(vector<string>& words, string s) {
        if(words.size() != s.size()) {
            return false;
        }
        int size = s.size();
        for(int i = 0; i < size; ++i) {
            if(words[i][0] != s[i]) {
                return false;
            }
        }
        return true;
    }
};
