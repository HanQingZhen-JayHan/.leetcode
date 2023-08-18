/*
 * @lc app=leetcode id=211 lang=cpp
 *
 * [211] Design Add and Search Words Data Structure
 *
 * https://leetcode.com/problems/design-add-and-search-words-data-structure/description/
 *
 * algorithms
 * Medium (43.93%)
 * Likes:    7105
 * Dislikes: 406
 * Total Accepted:    549.1K
 * Total Submissions: 1.2M
 * Testcase Example: '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n' +
  '[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * Design a data structure that supports adding new words and finding if a
 * string matches any previously added string.
 *
 * Implement the WordDictionary class:
 *
 *
 * WordDictionary() Initializes the object.
 * void addWord(word) Adds word to the data structure, it can be matched
 * later.
 * bool search(word) Returns true if there is any string in the data structure
 * that matches word or false otherwise. word may contain dots '.' where dots
 * can be matched with any letter.
 *
 *
 *
 * Example:
 *
 *
 * Input
 *
 * ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
 * [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
 * Output
 * [null,null,null,null,false,true,true,true]
 *
 * Explanation
 * WordDictionary wordDictionary = new WordDictionary();
 * wordDictionary.addWord("bad");
 * wordDictionary.addWord("dad");
 * wordDictionary.addWord("mad");
 * wordDictionary.search("pad"); // return False
 * wordDictionary.search("bad"); // return True
 * wordDictionary.search(".ad"); // return True
 * wordDictionary.search("b.."); // return True
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= word.length <= 25
 * word in addWord consists of lowercase English letters.
 * word in search consist of '.' or lowercase English letters.
 * There will be at most 2 dots in word for search queries.
 * At most 10^4 calls will be made to addWord and search.
 *
 *
 */

// @lc code=start
#include "BaseSolution.h"
#include "PrintTools.h"
#include <string>
#include <unordered_map>
#include <unordered_set>
class WordDictionary : BaseSolution {
public:
    void test() {
        addWord("bad");
        addWord("dad");
        addWord("mad");
        addWord("a");
        printBool(search("pad"));
        printBool(search("bad"));
        printBool(search(".ad"));
        printBool(search("b.."));
        printBool(search("a"));
        printBool(search(""));
    }

    // private:
    //     unordered_set<string> data;
    // // read heavy friendly
    // void addWord(string word) {
    //     if(word.empty() || data.find(word) != data.end()) {
    //         return;
    //     }
    //     data.insert(word);

    //     int size = word.size();
    //     for(int i = 0; i < size; ++i) {
    //         char ci = word[i];
    //         word[i] = '.';
    //         for(int j = 0; j < size; ++j) {
    //             char cj = word[j];
    //             word[j] = '.';
    //             data.insert(word);
    //             word[j] = cj;
    //         }
    //         word[i] = ci;
    //     }
    //     print(data);
    // }

    // solution2 : write heavy friendly
    // bool search(string word) {
    //     int size = word.size();
    //     if(size < 1 || data.find(size) == data.end()) {
    //         return false;
    //     }
    //     if(data[size].find(word) != data[size].end()) {
    //         return true;
    //     }

    //     for(auto it : data[size]) {
    //         bool flag = true;
    //         for(int i = 0; i < size && flag; ++i) {
    //             flag = it[i] == word[i] || word[i] == '.';
    //         }
    //         if(flag) {
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    struct Node {
        bool isWord = false;
        char c = ' ';
        Node* branches[26] = { nullptr };

        void build(string& word, int index) {

            if(index >= word.size()) {
                isWord = word.size() > 0;
                return;
            }
            int branchIndex = word[index] - 'a';
            if(branches[branchIndex] == nullptr) {
                branches[branchIndex] = new Node();
                branches[branchIndex]->c = word[index];
            }
            branches[branchIndex]->build(word, index + 1);
        }
        bool search(string& word, int index) {

            if(index == word.size()) {
                return isWord;
            }
            if(word[index] == '.') {
                for(int i = 0; i < 26; ++i) {
                    if(branches[i] != nullptr && branches[i]->search(word, index + 1)) {
                        return true;
                    }
                }
            } else {
                int branchIndex = word[index] - 'a';
                Node* branch = branches[branchIndex];
                if(branch != nullptr) {
                    return branch->search(word, index + 1);
                }
            }
            return false;
        }
    };

private:
    Node root;

public:
    WordDictionary() {}

    void addWord(string word) {
        printInput(word);
        root.build(word, 0);
    }

    bool search(string word) { return root.search(word, 0); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
