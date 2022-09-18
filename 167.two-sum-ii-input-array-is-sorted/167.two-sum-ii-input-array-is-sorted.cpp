/*
 * @lc app=leetcode id=167 lang=cpp
 *
 * [167] Two Sum II - Input Array Is Sorted
 */

// @lc code=start
class Solution {
public:
    // hash map solution
    // time complexity: o(n)
    // space complexity: o(n)
    /*
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answear;
        unordered_map<int, int> map;
        for (int i = 0; i < numbers.size(); ++i) {
            int numToFind = target - numbers[i];
            if (map.find(numToFind) != map.end()) {
                // + 1: 1-indexed array
                answear.push_back(min(i + 1, map[numToFind] + 1));
                answear.push_back(max(i + 1, map[numToFind] + 1));
                break;
            }
            map[numbers[i]] = i;
        }
        return answear;
    }
    */
    // two-pointers solution
    // time complexity: o(n)
    // space complexity: o(1)
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> answear;
        int left = 0;
        int right = numbers.size() - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] == target) {
                answear.push_back(left + 1);
                answear.push_back(right + 1);
                break;
            } else if (numbers[left] + numbers[right] < target) {
                ++left;
            } else {
                --right;
            }
        }
        return answear;
    }
};
// @lc code=end

