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
        // inc(data);
        // inc(data);
        // inc(data);
        inc(data1);
        //inc(data1);
        inc(data2);
        printTest();
        inc(data2);
        printTest();
        inc(data1);
        printTest();
        inc(data2);
        printTest();
        dec(data1);
        printTest();
        dec(data1);
        printTest();
        dec(data);
        printTest();
        dec(data2);
        printTest();
    }
    void printTest() {
        // for(auto it: cache){
        //     cout<<"key: "<<it.first<<", fre: "<<it.second<<endl;
        // }
        Node* tmp = min;
        while(tmp != nullptr) {
            cout << "fre: " << tmp->fre << ", keys: ";
            for(auto it : tmp->keys) {
                cout << it << ",";
            }
            cout << endl;
            tmp = tmp->next;
        }

        printOutput("min:" + getMinKey());
        printOutput("max:" + getMaxKey());
        cout << endl;
    }
    struct Node {
        Node* pre;
        Node* next;
        int fre;
        unordered_multiset<string> keys;

    public:
        Node(const int f, const string& key)
        : fre(f), pre(nullptr), next(nullptr) {
            keys.insert(key);
        }
    };

private:
    Node* min = nullptr;
    Node* max = nullptr;
    // key:frequency
    unordered_map<string, int> cache;
    // frequency: key list
    unordered_map<int, Node*> frequencies;


public:
    AllOne() {}

    void dec(string key) {
        auto t = cache.find(key);
        if(t == cache.end()) {
            // not find
            // do nothing
        } else {
            // find key
            int fre = t->second;
            auto it = frequencies[fre];
            if(fre > 1) {
                if(frequencies.find(fre - 1) != frequencies.end()) {
                    // find next frequency
                    frequencies[fre - 1]->keys.insert(key);

                } else {
                    Node* data = new Node(fre - 1, key);
                    if(it == min) {
                        // min
                        it->pre = data;
                        data->next = it;
                        min = data;
                    } else {
                        Node* pre = it->pre;
                        it->pre = data;
                        data->next = it;
                        pre->next = data;
                        data->pre = pre;
                    }
                    frequencies[fre - 1] = data;
                }
                cache[key] = fre - 1;
            } else {
                // fre <= 1
                cache.erase(key);
            }
            // remove key from old set
            it->keys.erase(key);
            if(it->keys.empty()) {
                // remove it
                if(it == min) {
                    min = it->next;
                } else if(it == max) {
                    max = it->pre;
                    max->next = nullptr;
                } else {
                    it->pre->next = it->next;
                    it->next->pre = it->pre;
                }
                delete it;
                frequencies.erase(fre);
            }
        }
    }

    void inc(string key) {
        auto t = cache.find(key);
        if(t == cache.end()) {
            // not find
            if(min != nullptr && min->fre == 1) {
                min->keys.insert(key);
            } else {
                Node* data = new Node(1, key);

                data->next = min;
                if(min != nullptr) {
                    min->pre = data;
                    min = data;
                } else {
                    min = data;
                    max = min;
                }
                frequencies[1] = data;
            }
            cache[key] = 1;
        } else {
            // find key
            int fre = t->second;
            auto it = frequencies[fre];
            cache[key] = fre + 1;
            if(frequencies.find(fre + 1) != frequencies.end()) {
                // find next frequency
                frequencies[fre + 1]->keys.insert(key);

            } else {
                Node* data = new Node(fre + 1, key);
                if(it == max) {
                    // maximum
                    it->next = data;
                    data->pre = it;
                    max = data;
                } else {
                    Node* next = it->next;
                    it->next = data;
                    data->pre = it;
                    next->pre = data;
                    data->next = next;
                }
                frequencies[fre + 1] = data;
            }
            // remove key from old set
            it->keys.erase(key);
            if(it->keys.empty()) {
                // remove it
                if(it == min) {
                    min = it->next;
                } else {
                    it->pre->next = it->next;
                    it->next->pre = it->pre;
                }
                frequencies.erase(fre);
                delete it;
            }
        }
    }

    string getMaxKey() {
        if(max == nullptr || max->keys.empty()) {
            return "";
        }
        return *max->keys.cbegin();
    }

    string getMinKey() {
        if(min == nullptr || min->keys.empty()) {
            return "";
        }
        return *min->keys.cbegin();
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
