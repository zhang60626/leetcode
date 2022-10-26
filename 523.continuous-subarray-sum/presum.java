class Solution {
    // prefix sum
    // time complexity: o(n). n: length of nums
    // space complexity: o(min(n, k))
    public boolean checkSubarraySum(int[] nums, int k) {
        int n = nums.length;
        int presum = 0;
        Map<Integer, Integer> map = new HashMap(Map.of(0, 0));
        
        for (int i = 0; i < n; i++) {
            presum += nums[i];
            int rem = presum % k;
            if (!map.containsKey(rem)) {
                map.put(rem, i + 1);
            } else if (map.get(rem) < i) { // subarray size at least two
                return true;
            }
        }
        
        return false;
    }
}
