class Solution {
    // time complexity: o(n * k), n: length of nums 
    // space complexity: o(k)
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap();
        
        for (int i = 0; i < nums.length; i++) {
            if (map.containsValue(nums[i])) return true; 
            map.put(i, nums[i]);
            if (i - k >= 0) map.remove(i - k);
        }
        
        return false;
    }
}
