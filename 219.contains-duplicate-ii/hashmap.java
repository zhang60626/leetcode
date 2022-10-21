class Solution {
    // time complexity: o(n), n: length of nums
    // space complexity: o(k)
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Map<Integer, Integer> map = new HashMap();
        
        // use nums[i] as key, index as value
        // containsKey() has a o(1) time complexity while 
        // containsValue() has a o(k) time complexity
        for (int i = 0; i < nums.length; i++) {
            if (map.containsKey(nums[i])) return true; 
            map.put(nums[i], i);
            if (i - k >= 0) map.remove(nums[i - k]);
        }
        
        return false;
    }
}
