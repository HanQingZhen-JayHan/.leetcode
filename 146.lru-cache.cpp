/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Medium (40.00%)
 * Likes:    19093
 * Dislikes: 850
 * Total Accepted:    1.4M
 * Total Submissions: 3.4M
 * Testcase Example: '["LRUCache","put","put","get","put","get","put","get","get","get"]\n' +
  '[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * Design a data structure that follows the constraints of a Least Recently
 * Used (LRU) cache.
 *
 * Implement the LRUCache class:
 *
 *
 * LRUCache(int capacity) Initialize the LRU cache with positive size
 * capacity.
 * int get(int key) Return the value of the key if the key exists, otherwise
 * return -1.
 * void put(int key, int value) Update the value of the key if the key exists.
 * Otherwise, add the key-value pair to the cache. If the number of keys
 * exceeds the capacity from this operation, evict the least recently used
 * key.
 *
 *
 * The functions get and put must each run in O(1) average time complexity.
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * Output
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 *
 * Explanation
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // cache is {1=1}
 * lRUCache.put(2, 2); // cache is {1=1, 2=2}
 * lRUCache.get(1);    // return 1
 * lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
 * lRUCache.get(2);    // returns -1 (not found)
 * lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
 * lRUCache.get(1);    // return -1 (not found)
 * lRUCache.get(3);    // return 3
 * lRUCache.get(4);    // return 4
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= capacity <= 3000
 * 0 <= key <= 10^4
 * 0 <= value <= 10^5
 * At most 2 * 10^5 calls will be made to get and put.
 *
 *
 */

// @lc code=start
#include "BaseSolution.h"
#include "PrintTools.h"
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
class LRUCache : BaseSolution {
public:
    void test() {
        put(1, 1);
        put(2, 2);
        printOutput(get(1));
        put(3, 3);
        printOutput(get(2));
        put(4, 4);
        printOutput(get(1));
        printOutput(get(3));
        printOutput(get(4));
    }

private:
    list<int> visited;
    // key-(fre,value,iterator)
    unordered_map<int, pair<int, list<int>::iterator>> cache;
    int cap;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        auto it = cache.find(key);
        if(it == cache.end()) {
            return -1;
        }

        visited.erase(it->second.second);
        visited.push_back(key);
        cache[key].second = --visited.end();

        return cache[key].first;
    }

    void put(int key, int value) {
        auto it = cache.find(key);

        if(it == cache.end()) {
            if(cache.size() >= cap) {
                cache.erase(visited.front());
                visited.pop_front();
            }
        } else {
            visited.erase(it->second.second);
        }
        visited.push_back(key);
        cache[key] = { value, --visited.end() };
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end
