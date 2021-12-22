/*
 * @lc app=leetcode id=387 lang=cpp
 *
 * [387] First Unique Character in a String
 */

// @lc code=start
class Solution {
public:
    // brute force
    // time complexity: o(n^2)
    // space complexity: o(1)
    /*
    int firstUniqChar(string s) {
        bool repeat = false;
        for (int i = 0; i < s.length(); ++i) {
            for (int j = 0; j < s.length(); ++j) {
                if (j == i) continue;
                if (s[i] == s[j]) {
                    repeat = true;
                    break;
                }
            }
            if (!repeat) return i;
            repeat = false;
        }
        return -1;
    }
    */
    // use a vector (slower than first solution)
    // time complexity: o(n^2)
    // space complexity: o(n)
    /*
    int firstUniqChar(string s) {
        vector<int> repeat(s.length(), 0);
        for (int i = 0; i < s.length(); ++i) {
            if (repeat[i]) continue;
            for (int j = i + 1; j < s.length(); ++j) {
                if (repeat[j]) continue;
                if (s[i] == s[j]) {
                    repeat[i] = 1;
                    repeat[j] = 1;
                }
            }
            if (!repeat[i]) return i;
        }
        return -1;
    }
    */
    // hash map
    // time complexity: o(n)
    // space complexity: o(n)
    int firstUniqChar(string s) {
        map<char, int> cmap;
        for (int i = 0; i < s.length(); ++i) {
            cmap[s[i]]++;
        }
        for (int i = 0; i < s.length(); ++i) {
            if (cmap[s[i]] == 1) return i;
        }
        return -1;
    }
};
// @lc code=end

