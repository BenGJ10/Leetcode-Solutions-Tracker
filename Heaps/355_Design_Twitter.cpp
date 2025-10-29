/*
355. Design Twitter
Link: https://leetcode.com/problems/design-twitter/

------------------------------------------------------
Problem Summary:
Design a simplified version of Twitter where users can:
    1. Post tweets.
    2. Follow/unfollow other users.
    3. Retrieve the 10 most recent tweet IDs in their news feed.
The news feed should include the user's own tweets and those of the users they follow,
ordered from most recent to oldest.

------------------------------------------------------
Example:
Input:
["Twitter", "postTweet", "getNewsFeed", "follow", "postTweet", "getNewsFeed"]
[[], [1, 5], [1], [1, 2], [2, 6], [1]]

Output:
[null, null, [5], null, null, [6, 5]]

Explanation:
User 1 posts tweet 5.
User 1’s news feed should return [5].
User 1 follows user 2.
User 2 posts tweet 6.
User 1’s news feed should return [6, 5].

------------------------------------------------------
Brute Force Approach:
1. Store all tweets with timestamps in a global list.
2. When fetching the news feed, iterate over all tweets and filter
   those by the user or their followees.
3. Sort by time and return the top 10.
- Time Complexity: O(N log N)
- Space Complexity: O(N)

------------------------------------------------------
Optimal Approach (Using Min-Heap / Priority Queue):
Idea:
- Maintain a mapping from user → tweets (with timestamps).
- Maintain a mapping from user → set of followees.
- For `getNewsFeed(userId)`:
    - Consider the user's tweets and all followees' tweets.
    - Push the most recent tweet of each user into a max-heap (by timestamp).
    - Pop up to 10 tweets while pushing previous tweets from the same user.
- This efficiently merges multiple sorted tweet lists (like K sorted lists).

Steps:
1. `postTweet`: Append (time, tweetId) to user's tweet list.
2. `follow`: Add followee to follower’s set.
3. `unfollow`: Remove followee from follower’s set.
4. `getNewsFeed`:
   - Use a max-heap to track the latest tweets.
   - Always push the previous tweet from the same user after popping.
   - Collect up to 10 most recent tweets.

- Time Complexity:
    * postTweet: O(1)
    * follow/unfollow: O(1)
    * getNewsFeed: O((n + f) log (n + f))
      (n = user tweets, f = followees)
- Space Complexity: O(N + F)
  (N = tweets, F = follow relationships)

------------------------------------------------------
*/

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Twitter {
public:
    int time;
    unordered_map<int, unordered_set<int>> followees;
    unordered_map<int, vector<pair<int, int>>> tweets;

    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    void follow(int followerId, int followeeId) {
        if (followerId == followeeId) return;
        followees[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        followees[followerId].erase(followeeId);
    }

    vector<int> getNewsFeed(int userId) {
        struct Node {
            int time;
            int tweetId;
            int userId;
            int index;
        };

        struct Compare {
            bool operator()(const Node &a, const Node &b) {
                return a.time < b.time;
            }
        };

        priority_queue<Node, vector<Node>, Compare> pq;

        if (!tweets[userId].empty()) {
            int idx = tweets[userId].size() - 1;
            pq.push({tweets[userId][idx].first, tweets[userId][idx].second, userId, idx});
        }

        for (auto &followee : followees[userId]) {
            if (!tweets[followee].empty()) {
                int idx = tweets[followee].size() - 1;
                pq.push({tweets[followee][idx].first, tweets[followee][idx].second, followee, idx});
            }
        }

        vector<int> feed;
        int count = 10;
        while (!pq.empty() && count--) {
            Node top = pq.top(); pq.pop();
            feed.push_back(top.tweetId);

            if (top.index > 0) {
                int prevIdx = top.index - 1;
                pq.push({tweets[top.userId][prevIdx].first,
                         tweets[top.userId][prevIdx].second,
                         top.userId, prevIdx});
            }
        }
        
        return feed;
    }
};

/*
Usage:
Twitter* obj = new Twitter();
obj->postTweet(userId, tweetId);
vector<int> feed = obj->getNewsFeed(userId);
obj->follow(followerId, followeeId);
obj->unfollow(followerId, followeeId);
*/
