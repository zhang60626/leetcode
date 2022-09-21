class Solution {
public:
    // Boyer-Moore Voting Algorithm
    // see https://leetcode.com/problems/majority-element/solution/
    // approach 6
    // time complexity: o(n)
    // space complexity: o(1)
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majority;
        for (int i = 0; i < nums.size(); ++i) {
            if (count == 0) majority = nums[i];
            if (nums[i] == majority) ++count;
            else --count;
        }
        return majority;
    }
}
