class Solution {
public:
    // hashmap
    int majorityElement(vector<int>& nums) {
        int hsize = nums.size() / 2;
        while (true) {
            int majority = nums[rand() % nums.size()];
            int count = 0;
            for (int i = 0; i < nums.size(); ++i) {
                if (majority == nums[i]) count++;
            }
            if (count > hsize) return majority;
        }
        return -1;
    }
};