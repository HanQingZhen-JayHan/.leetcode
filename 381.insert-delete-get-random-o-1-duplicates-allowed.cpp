/*
 * @lc app=leetcode id=381 lang=cpp
 *
 * [381] Insert Delete GetRandom O(1) - Duplicates allowed
 *
 * https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/description/
 *
 * algorithms
 * Hard (35.53%)
 * Likes:    2137
 * Dislikes: 139
 * Total Accepted:    129.2K
 * Total Submissions: 364.2K
 * Testcase Example: '["RandomizedCollection","insert","insert","insert","getRandom","remove","getRandom"]\n' +
  '[[],[1],[1],[2],[],[1],[]]'
 *
 * RandomizedCollection is a data structure that contains a collection of
 * numbers, possibly duplicates (i.e., a multiset). It should support inserting
 * and removing specific elements and also reporting a random element.
 *
 * Implement the RandomizedCollection class:
 *
 *
 * RandomizedCollection() Initializes the empty RandomizedCollection
 * object.
 * bool insert(int val) Inserts an item val into the multiset, even if the item
 * is already present. Returns true if the item is not present, false
 * otherwise.
 * bool remove(int val) Removes an item val from the multiset if present.
 * Returns true if the item is present, false otherwise. Note that if val has
 * multiple occurrences in the multiset, we only remove one of them.
 * int getRandom() Returns a random element from the current multiset of
 * elements. The probability of each element being returned is linearly related
 * to the number of the same values the multiset contains.
 *
 *
 * You must implement the functions of the class such that each function works
 * on average O(1) time complexity.
 *
 * Note: The test cases are generated such that getRandom will only be called
 * if there is at least one item in the RandomizedCollection.
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["RandomizedCollection", "insert", "insert", "insert", "getRandom",
 * "remove", "getRandom"]
 * [[], [1], [1], [2], [], [1], []]
 * Output
 * [null, true, false, true, 2, true, 1]
 *
 * Explanation
 * RandomizedCollection randomizedCollection = new RandomizedCollection();
 * randomizedCollection.insert(1);   // return true since the collection does
 * not contain 1.
 * ⁠                                 // Inserts 1 into the collection.
 * randomizedCollection.insert(1);   // return false since the collection
 * contains 1.
 * ⁠                                 // Inserts another 1 into the collection.
 * Collection now contains [1,1].
 * randomizedCollection.insert(2);   // return true since the collection does
 * not contain 2.
 * ⁠                                 // Inserts 2 into the collection.
 * Collection now contains [1,1,2].
 * randomizedCollection.getRandom(); // getRandom should:
 * ⁠                                 // - return 1 with probability 2/3, or
 * ⁠                                 // - return 2 with probability 1/3.
 * randomizedCollection.remove(1);   // return true since the collection
 * contains 1.
 * ⁠                                 // Removes 1 from the collection.
 * Collection now contains [1,2].
 * randomizedCollection.getRandom(); // getRandom should return 1 or 2, both
 * equally likely.
 *
 *
 *
 * Constraints:
 *
 *
 * -2^31 <= val <= 2^31 - 1
 * At most 2 * 10^5 calls in total will be made to insert, remove, and
 * getRandom.
 * There will be at least one element in the data structure when getRandom is
 * called.
 *
 *
 */

// @lc code=start
#include "BaseSolution.h"
#include "PrintTools.h"
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
class RandomizedCollection : BaseSolution {
public:
    void test() {

        insert(10);
        remove(10);
        insert(10);
        // insert(20);
        // insert(20);
        // insert(30);
        // insert(30);

        // remove(10);
        // remove(20);
        // remove(20);
        // remove(10);
        // remove(30);
        // insert(40);
        // remove(30);
        // remove(30);

        // printOutput(getRandom());
        // printOutput(getRandom());
        // printOutput(getRandom());
        // printOutput(getRandom());
    }

private:
    // val: index list
    unordered_map<int, unordered_set<int>> data;
    vector<int> probabilities;

public:
    RandomizedCollection() {}

    bool insert(int val) {
        bool r = data.find(val) == data.end();

        probabilities.push_back(val);
        data[val].insert(probabilities.size() - 1);
        return r;
    }

    bool remove(int val) {
        bool r = data.find(val) != data.end();
        if(r) {

            // cache last item
            int last = probabilities.back();
            int lastIndex = probabilities.size() - 1;

            // O(1) //delete last item
            probabilities.pop_back();
            data[last].erase(lastIndex);
            if(data[last].empty()) {
                data.erase(last);
            }

            if(last != val) {
                // set
                auto& it = data[val];
                int index = *(it.cbegin());
                it.erase(it.begin());

                // key point
                probabilities[index] = last;
                data[last].insert(index);

                if(it.empty()) {
                    data.erase(val);
                }
            }
        }
        return r;
    }

    int getRandom() {
        int size = probabilities.size();
        int index = rand() % size;
        return probabilities[index];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end
