/*
 * @lc app=leetcode id=355 lang=cpp
 *
 * [355] Design Twitter
 *
 * https://leetcode.com/problems/design-twitter/description/
 *
 * algorithms
 * Medium (34.76%)
 * Likes:    3295
 * Dislikes: 417
 * Total Accepted:    133.7K
 * Total Submissions: 352.1K
 * Testcase Example: '["Twitter","postTweet","getNewsFeed","follow","postTweet","getNewsFeed","unfollow","getNewsFeed"]\n' +
  '[[],[1,5],[1],[1,2],[2,6],[1],[1,2],[1]]'
 *
 * Design a simplified version of Twitter where users can post tweets,
 * follow/unfollow another user, and is able to see the 10 most recent tweets
 * in the user's news feed.
 *
 * Implement the Twitter class:
 *
 *
 * Twitter() Initializes your twitter object.
 * void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId
 * by the user userId. Each call to this function will be made with a unique
 * tweetId.
 * List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs
 * in the user's news feed. Each item in the news feed must be posted by users
 * who the user followed or by the user themself. Tweets must be ordered from
 * most recent to least recent.
 * void follow(int followerId, int followeeId) The user with ID followerId
 * started following the user with ID followeeId.
 * void unfollow(int followerId, int followeeId) The user with ID followerId
 * started unfollowing the user with ID followeeId.
 *
 *
 *
 * Example 1:
 *
 *
 * Input
 * ["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet",
 * "getNewsFeed", "unfollow", "getNewsFeed"]
 * [[], [1, 5], [1], [1, 2], [2, 6], [1], [1, 2], [1]]
 * Output
 * [null, null, [5], null, null, [6, 5], null, [5]]
 *
 * Explanation
 * Twitter twitter = new Twitter();
 * twitter.postTweet(1, 5); // User 1 posts a new tweet (id = 5).
 * twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1
 * tweet id -> [5]. return [5]
 * twitter.follow(1, 2);    // User 1 follows user 2.
 * twitter.postTweet(2, 6); // User 2 posts a new tweet (id = 6).
 * twitter.getNewsFeed(1);  // User 1's news feed should return a list with 2
 * tweet ids -> [6, 5]. Tweet id 6 should precede tweet id 5 because it is
 * posted after tweet id 5.
 * twitter.unfollow(1, 2);  // User 1 unfollows user 2.
 * twitter.getNewsFeed(1);  // User 1's news feed should return a list with 1
 * tweet id -> [5], since user 1 is no longer following user 2.
 *
 *
 *
 * Constraints:
 *
 *
 * 1 <= userId, followerId, followeeId <= 500
 * 0 <= tweetId <= 10^4
 * All the tweets have unique IDs.
 * At most 3 * 10^4 calls will be made to postTweet, getNewsFeed, follow, and
 * unfollow.
 *
 *
 */

// @lc code=start
#include "BaseSolution.h"
#include "PrintTools.h"
#include <algorithm>
#include <cstddef>
#include <memory>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>
class Tweet {
    friend class User;
    friend class Compare;

private:
    int tweetId;
    int timestamp;
    shared_ptr<Tweet> next;

public:
    Tweet(int id, int t, shared_ptr<Tweet> n)
    : tweetId(id), timestamp(t), next(n) {}
};
class Compare {
public:
    // timestamp descending
    bool operator()(shared_ptr<Tweet> below, shared_ptr<Tweet> above) {
        if(below->timestamp < above->timestamp) {
            return true;
        }

        return false;
    }
};
class User {
private:
    int userId;
    unordered_set<shared_ptr<User>> followees = {};
    // default value is nullptr
    shared_ptr<Tweet> currentTweet;
    const int MOST_RECENT_COUNT = 10;

public:
    User(int id) : userId(id) {}
    void follow(shared_ptr<User> followee) { followees.insert(followee); }
    void unfollow(shared_ptr<User> followee) { followees.erase(followee); }
    void postTweet(int tweetId, int time) {
        currentTweet = make_shared<Tweet>(tweetId, time, currentTweet);
    }
    vector<int> getNewsFeed() {
        vector<int> tweets;
        // Maximum Heap
        priority_queue<shared_ptr<Tweet>, vector<shared_ptr<Tweet>>, Compare> ts;
        if(currentTweet) {
            ts.push(currentTweet);
        }
        // O(n): can be improved by sorting user based on latest tweet's timestamp 
        // if read heavy, we need to sort user in following process.
        // if write heavy, we can keep it
        for(auto user : followees) {
            if(user->currentTweet) {
                ts.push(user->currentTweet);
            }
        }
        // BFS
        while(!ts.empty() && tweets.size() < MOST_RECENT_COUNT) {
            const shared_ptr<Tweet> t = ts.top();
            tweets.push_back(t->tweetId);
            ts.pop();
            print(vector<int>{ t->tweetId, t->timestamp });
            // test if set
            if(t->next) {
                ts.push(t->next);
            }
        }
        return tweets;
    }
};
class Twitter : public BaseSolution {
private:
    unordered_map<int, shared_ptr<User>> data = {};
    int time = 0;

public:
    void test() {
        postTweet(1, 0);
        postTweet(1, 1);
        postTweet(2, 2);
        follow(1, 2);
        postTweet(1, 3);
        printOutput(getNewsFeed(1));
    }

public:
    Twitter() {}

    void postTweet(int userId, int tweetId) {
        if(data.find(userId) == data.end()) {
            data.emplace(userId, make_shared<User>(userId));
        }
        data[userId]->postTweet(tweetId, ++time);
    }

    vector<int> getNewsFeed(int userId) {
        if(data.find(userId) != data.end()) {
            return data[userId]->getNewsFeed();
        }
        return vector<int>();
    }

    void follow(int followerId, int followeeId) {
        if(data.find(followerId) == data.end()) {
            data.emplace(followerId, make_shared<User>(followerId));
        }
        if(data.find(followeeId) == data.end()) {
            data.emplace(followeeId, make_shared<User>(followeeId));
        }
        data[followerId]->follow(data[followeeId]);
    }

    void unfollow(int followerId, int followeeId) {
        if(data.find(followerId) == data.end()) {
            data.emplace(followerId, make_shared<User>(followerId));
        }
        if(data.find(followeeId) == data.end()) {
            data.emplace(followeeId, make_shared<User>(followeeId));
        }
        data[followerId]->unfollow(data[followeeId]);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */
// @lc code=end
