class Solution {
    // avoid sort
    // see https://leetcode.com/problems/arithmetic-subarrays/discuss/910421/C%2B%2B-Two-Approaches-(140-vs-28ms)
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        List<Boolean> answer = new ArrayList();
        
        for (int i = 0; i < l.length; i++) {
            answer.add(isArithmetic(nums, l[i], r[i]));
        }
        
        return answer;
    }
    
    private Boolean isArithmetic(int[] nums, int l, int r) {
        int max = Integer.MIN_VALUE;
        int min = Integer.MAX_VALUE;
        int len = r - l + 1;
        boolean[] exist = new boolean[len];
        int diff;
        
        for (int i = l; i <= r; i++) {
            if (max < nums[i]) max = nums[i];
            if (min > nums[i]) min = nums[i];
        }
        
        if ((max - min) % (len - 1) != 0) return false;
        else diff = (max - min) / (len - 1);
        
        if (diff == 0) return true;
        
        for (int i = l; i <= r; i++) {
            if ((nums[i] - min) % diff != 0) return false;
            int idx = (nums[i] - min) / diff;
            if (idx >= len || exist[idx]) return false;
            else exist[idx] = true;
        }
        
        return true;
    }
}
