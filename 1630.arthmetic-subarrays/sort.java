import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;

class Solution {
    public List<Boolean> checkArithmeticSubarrays(int[] nums, int[] l, int[] r) {
        int n = nums.length;
        List<Boolean> answer = new ArrayList();
        
        for (int i = 0; i < l.length; i++) {
            answer.add(isArithmetic(Arrays.copyOfRange(nums, l[i], r[i] + 1)));
        }
        
        return answer;
    }
    
    private boolean isArithmetic(int[] nums) {
        Arrays.sort(nums);
        int d = nums[1] - nums[0];
        
        for (int i = 1; i < nums.length; i++) {
            if (nums[i] - nums[i - 1] != d) return false;
        }
        
        return true;
    }
}
