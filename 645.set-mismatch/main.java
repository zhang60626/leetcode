class Solution {
    public int[] findErrorNums(int[] nums) {
        int n = nums.length;
        int dupNum = 0;
        boolean[] seen = new boolean[n + 1];
        
        for (int i = 0; i < n; i++) {
            if (seen[nums[i]]) dupNum = nums[i];
            else seen[nums[i]] = true;
        }
        
        for (int i = 1; i < n + 1; i++) {
            if (!seen[i]) return new int[] {dupNum, i};
        }
        
        return new int[2]; // dummy return
    }
}
