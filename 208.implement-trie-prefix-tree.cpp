/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (58.48%)
 * Likes:    10700
 * Dislikes: 120
 * Total Accepted:    867K
 * Total Submissions: 1.4M
 * Testcase Example: '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * A trie (pronounced as "try") or prefix tree is a tree data structure used to
 * efficiently store and retrieve keys in a dataset of strings. There are
 * various applications of this data structure, such as autocomplete and
 * spellchecker.
 *
 * Implement the Trie class:
 *
 *
 * Trie() Initializes the trie object.
 * void insert(String word) Inserts the string word into the trie.
 * boolean search(String word) Returns true if the string word is in the trie
 * (i.e., was inserted before), and false otherwise.
 * boolean startsWith(String prefix) Returns true if there is a previously
 * inserted string word that has the prefix prefix, and false otherwise.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 * [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 * Output
 * [null, null, true, false, true, null, true]
 *
 * Explanation
 * Trie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple");   // return True
 * trie.search("app");     // return False
 * trie.startsWith("app"); // return True
 * trie.insert("app");
 * trie.search("app");     // return True
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word.length, prefix.length <= 2000
 * word and prefix consist only of lowercase English letters.
 * At most 3 * 10^4 calls in total will be made to insert, search, and
 * startsWith.
 *
 *
 */

// @lc code=start
#include "BaseSolution.h"
class Trie : BaseSolution {
public:
    void test() {
        // insert("string word");
        // search("string word");
        startsWith("a");
    }
    struct Node {
        Node* dictionary[26] = { nullptr };
        bool isWord = false;
    };

private:
    Node root;

    Node* generateNode(Node& root, char c) {
        int index = c - 'a';
        if(root.dictionary[index] == nullptr) {
            root.dictionary[index] = new Node();
        }
        return root.dictionary[index];
    }
    Node* getNode(Node& root, char c) { return root.dictionary[c - 'a']; }

public:
    Trie() {}

    void insert(string word) {
        if(word.empty()) {
            return;
        }
        Node* ptr = generateNode(root, word[0]);
        for(int i = 1; i < word.size(); ++i) {
            ptr = generateNode(*ptr, word[i]);
        }
        ptr->isWord = true;
    }

    bool search(string word) {
        if(word.empty()) {
            return false;
        }
        Node* ptr = getNode(root, word[0]);
        for(int i = 1; i < word.size() && ptr != nullptr; ++i) {
            ptr = getNode(*ptr, word[i]);
        }
        return ptr != nullptr && ptr->isWord;
    }

    bool startsWith(string prefix) {
        if(prefix.empty()) {
            return false;
        }
        Node* ptr = getNode(root, prefix[0]);
        for(int i = 1; i < prefix.size() && ptr != nullptr; ++i) {
            ptr = getNode(*ptr, prefix[i]);
        }
        return ptr != nullptr;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
