/*
 * @lc app=leetcode id=784 lang=cpp
 *
 * [784] Letter Case Permutation
 */

// @lc code=start
class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> result;
        backtrack(s, result, 0);
        return result;
    }
    
    void backtrack(string& s, vector<string>& result, int index) {
        if (index >= s.length()) {
            result.push_back(s);
            return;
        }
        if (isdigit(s[index])) {
            backtrack(s, result, index + 1);
            return;
        }
        
        backtrack(s, result, index + 1);
        if (islower(s[index])) {        
            s[index] = toupper(s[index]);
            backtrack(s, result, index + 1);            
        } else if (isupper(s[index])) {
            s[index] = tolower(s[index]);
            backtrack(s, result, index + 1);
        }
    }
};

// @lc code=end

