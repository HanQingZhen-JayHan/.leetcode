/*
 * @lc app=leetcode id=432 lang=cpp
 *
 * [432] All O`one Data Structure
 *
 * https://leetcode.com/problems/all-oone-data-structure/description/
 *
 * algorithms
 * Hard (36.14%)
 * Likes:    1427
 * Dislikes: 159
 * Total Accepted:    70.8K
 * Total Submissions: 193.7K
 * Testcase Example: '["AllOne","inc","inc","getMaxKey","getMinKey","inc","getMaxKey","getMinKey"]\n' +
  '[[],["hello"],["hello"],[],[],["leet"],[],[]]'
 *
 * Design a data structure to store the strings' count with the ability to
 * return the strings with minimum and maximum counts.
 *
 * Implement the AllOne class:
 *
 *
 * AllOne() Initializes the object of the data structure.
 * inc(String key) Increments the count of the string key by 1. If key does not
 * exist in the data structure, insert it with count 1.
 * dec(String key) Decrements the count of the string key by 1. If the count of
 * key is 0 after the decrement, remove it from the data structure. It is
 * guaranteed that key exists in the data structure before the decrement.
 * getMaxKey() Returns one of the keys with the maximal count. If no element
 * exists, return an empty string "".
 * getMinKey() Returns one of the keys with the minimum count. If no element
 * exists, return an empty string "".
 *
 *
 * Note that each function must run in O(1) average time complexity.
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey",
 * "getMinKey"]
 * [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
 * Output
 * [null, null, null, "hello", "hello", null, "hello", "leet"]
 *
 * Explanation
 * AllOne allOne = new AllOne();
 * allOne.inc("hello");
 * allOne.inc("hello");
 * allOne.getMaxKey(); // return "hello"
 * allOne.getMinKey(); // return "hello"
 * allOne.inc("leet");
 * allOne.getMaxKey(); // return "hello"
 * allOne.getMinKey(); // return "leet"
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= key.length <= 10
 * key consists of lowercase English letters.
 * It is guaranteed that for each call to dec, key is existing in the data
 * structure.
 * At most 5 * 10^4 calls will be made to inc, dec, getMaxKey, and getMinKey.
 *
 *
 */

// @lc code=start
#include "BaseSolution.h"
#include "PrintTools.h"
#include <cstddef>
#include <iterator>
#include <list>
#include <string>
#include <unordered_map>
#include <unordered_set>
class AllOne : public BaseSolution {
public:
    void test() {
        string data = "data ";
        string data1 = "data1";
        string data2 = "data2";
        inc(data);
        inc(data);
        inc(data1);
        inc(data2);
        cout << "data: 2, data1: 1, data2: 1" << endl;
        printTest();

        inc(data2);
        cout << "data: 2, data1: 1, data2: 2" << endl;
        printTest();

        inc(data1);
        cout << "data: 2, data1: 2, data2: 2" << endl;
        printTest();

        inc(data2);
        cout << "data: 2, data1: 2, data2: 3" << endl;
        printTest();

        dec(data1);
        cout << "data: 2, data1: 1, data2: 3" << endl;
        printTest();

        dec(data1);
        cout << "data: 2, data1: 0, data2: 3" << endl;
        printTest();

        dec(data);
        cout << "data: 1, data1: 0, data2: 3" << endl;
        printTest();

        dec(data2);
        cout << "data: 1, data1: 0, data2: 2" << endl;
        printTest();
    }
    void printTest() {
        for(auto it : sortedNode) {
            cout << "fre: " << it.fre << ", keys: ";
            for(auto it : it.keys) {
                cout << it << ",";
            }
            cout << endl;
        }

        printOutput("min:" + getMinKey());
        printOutput("max:" + getMaxKey());
        cout << endl;
    }
    struct Node {
        int fre;
        unordered_set<string> keys;
    };

private:
    // key:frequency
    unordered_map<string, list<Node>::iterator> cache;
    // double linked list
    list<Node> sortedNode;


public:
    AllOne() {}

    void dec(string key) {
        auto t = cache.find(key);
        if(t == cache.end()) {
            // not find
            // do nothing
        } else {
            // cur: key's current position; target(pre position): target position after decreasing 1
            auto cur = cache[key], target = prev(cur);
            cache.erase(key);
            if(cur->fre > 1) {
                // insert the real node
                if(cur == sortedNode.cbegin() || target->fre < cur->fre - 1) {
                    target = sortedNode.insert(cur, { cur->fre - 1, {} });
                }
                target->keys.insert(key);
                cache[key] = target;
            }

            cur->keys.erase(key);
            if(cur->keys.empty()) {
                sortedNode.erase(cur);
            }
        }
    }

    void inc(string key) {
        auto t = cache.find(key);
        if(t == cache.end()) {
            // insert a fake node
            cache[key] = sortedNode.insert(sortedNode.cbegin(), { 0, { key } });
        }
        // cur: key's current position; target(next position): target position after increasing 1
        auto cur = cache[key], target = next(cur);
        // insert the real node
        if(target == sortedNode.end() || target->fre > cur->fre + 1) {
            // inserts value before pos.
            target = sortedNode.insert(target, { cur->fre + 1, {} });
        }
        target->keys.insert(key);
        cache[key] = target;

        cur->keys.erase(key);
        if(cur->keys.empty()) {
            sortedNode.erase(cur);
        }
    }

    string getMaxKey() {
        if(sortedNode.empty()) {
            return "";
        }
        return *(sortedNode.crbegin()->keys.cbegin());
    }

    string getMinKey() {
        if(sortedNode.empty()) {
            return "";
        }
        return *(sortedNode.cbegin()->keys.cbegin());
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
// @lc code=end
