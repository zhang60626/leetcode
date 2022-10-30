class Solution {
    public int smallestRangeII(int[] nums, int k) {
        int n = nums.length;
        
        Arrays.sort(nums);
        
        if (nums[n - 1] - nums[0] <= k) return nums[n - 1] - nums[0];

        int minScore = nums[n - 1] - nums[0];
        for (int i = 0; i < n - 1; i++) {
            int mn = Math.min(nums[0] + k, nums[i + 1] - k);
            int mx = Math.max(nums[i] + k, nums[n - 1] - k);
            minScore = Math.min(minScore, mx - mn);
        }
    
        return minScore;
    }
}
