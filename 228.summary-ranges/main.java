class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> output = new ArrayList();
        int n = nums.length;
        
        if (n == 0) return output;
        
        int start = 0;
        for (int i = 0; i < n; i++) {
            if (i - 1 < 0) continue;
            if (nums[i] != nums[i - 1] + 1) {
                if (i - 1 == start) output.add(Integer.toString(nums[start]));
                else output.add(nums[start] + "->" + nums[i - 1]);
                start = i;
            }
        }
        if (start == n - 1) output.add(Integer.toString(nums[start]));
        else output.add(nums[start] + "->" + nums[n - 1]);
        
        return output;
    }
}
