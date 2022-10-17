//Given an integer array nums that may contain duplicates, return all possible 
//subsets (the power set). 
//
// The solution set must not contain duplicate subsets. Return the solution in 
//any order. 
//
// 
// Example 1: 
// Input: nums = [1,2,2]
//Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
// 
// Example 2: 
// Input: nums = [0]
//Output: [[],[0]]
// 
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// 
//
// Related Topics Array Backtracking Bit Manipulation 👍 6762 👎 189


//leetcode submit region begin(Prohibit modification and deletion)

import java.util.Arrays;
import java.util.LinkedList;

class Solution {
    List<List<Integer>> output;

    public List<List<Integer>> subsetsWithDup(int[] nums) {
        output = new LinkedList<>();

        Arrays.sort(nums);
        backtrace(nums, new LinkedList(), 0);

        return output;
    }

    private void backtrace(int[] nums, List<Integer> curr, int idx) {
        output.add(new LinkedList(curr));

        for (int i = idx; i < nums.length; i++) {
            if (i > idx && nums[i] == nums[i - 1]) continue;
            curr.add(nums[i]);
            backtrace(nums, curr, i + 1);
            curr.remove(curr.size() - 1);
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
