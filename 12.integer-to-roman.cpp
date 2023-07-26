#include "BaseSolution.h"
#include "PrintTools.h"
#include <map>
#include <unordered_map>
#include <vector>
class Solution12 : public BaseSolution {
public:
    void test() {
        int i = 1994;
        printInput(i);
        printOutput(intToRoman(i));
    }

public:
    string intToRoman(int num) {

        static vector<string> ones = { "", "I", "II", "III", "IV", "V", "VI",
            "VII", "VIII", "IX" };
        static vector<string> tens = { "", "X", "XX", "XXX", "XL", "L", "LX",
            "LXX", "LXXX", "XC" };
        static vector<string> hrns = { "", "C", "CC", "CCC", "CD", "D", "DC",
            "DCC", "DCCC", "CM" };
        static vector<string> ths = { "", "M", "MM", "MMM" };

        return ths[num / 1000] + hrns[(num % 1000) / 100] +
        tens[(num % 100) / 10] + ones[num % 10];

        // bak
        string res;
        static vector<char> order = { 'M', 'D', 'C', 'L', 'X', 'V', 'I' };
        static unordered_map<char, int> romanMap = { { 'I', 1 }, { 'V', 5 },
            { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
        static unordered_map<int, string> valueMap = { {
                                                       1000,
                                                       "M",
                                                       },
            { 500, "D" }, { 100, "C" }, { 50, "L" }, { 10, "X" }, { 5, "V" }, { 1, "I" } };
        int len = order.size();
        for(int i = 0; i < len; ++i) {
            int v = romanMap[order[i]];
            for(int j = i + 1; j < len; ++j) {
                int target = v - romanMap[order[j]];
                if(valueMap.find(target) == valueMap.end()) {
                    std::string s{ order[j], order[i] };
                    valueMap[target] = s;
                }
            }
        }

        return res;
    }
};