class Solution {
public:
    // sort
    // time complexity: o(n log(n))
    // space complexity: o(1) or o(n)
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};