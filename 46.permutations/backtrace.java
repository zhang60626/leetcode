//Given an array nums of distinct integers, return all the possible 
//permutations. You can return the answer in any order. 
//
// 
// Example 1: 
// Input: nums = [1,2,3]
//Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// 
// Example 2: 
// Input: nums = [0,1]
//Output: [[0,1],[1,0]]
// 
// Example 3: 
// Input: nums = [1]
//Output: [[1]]
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 6 
// -10 <= nums[i] <= 10 
// All the integers of nums are unique. 
// 
//
// Related Topics Array Backtracking 👍 13253 👎 221


import java.util.ArrayList;
import java.util.Arrays;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    List<List<Integer>> output;
    boolean[] marked;

    public List<List<Integer>> permute(int[] nums) {
        marked = new boolean[nums.length];
        output = new ArrayList();

        List<Integer> curr = new ArrayList();
        backtrace(curr, nums);
        return output;
    }

    private void backtrace(List<Integer> curr, int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            if (marked[i]) continue;
            marked[i] = true;
            curr.add(nums[i]);
            backtrace(curr, nums);
            marked[i] = false;
            curr.remove(curr.size() - 1);
        }

        if (curr.size() == nums.length) {
            output.add(new ArrayList(curr));
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
