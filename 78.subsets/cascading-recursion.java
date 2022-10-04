//Given an integer array nums of unique elements, return all possible subsets (
//the power set). 
//
// The solution set must not contain duplicate subsets. Return the solution in 
//any order. 
//
// 
// Example 1: 
//
// 
//Input: nums = [1,2,3]
//Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// 
//
// Example 2: 
//
// 
//Input: nums = [0]
//Output: [[],[0]]
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10 
// -10 <= nums[i] <= 10 
// All the numbers of nums are unique. 
// 
//
// Related Topics Array Backtracking Bit Manipulation 👍 12246 👎 176


import java.util.ArrayList;
import java.util.Arrays;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ret = new ArrayList<List<Integer>>();
        if (nums.length == 1) {
            ret.add(new ArrayList<Integer>());
            ret.add(new ArrayList<Integer>(Arrays.asList(nums[0])));
            return ret;
        }

        int n = nums[nums.length - 1];
        List<List<Integer>> list = subsets(Arrays.copyOfRange(nums, 0, nums.length - 1));
        ret.addAll(list);
        for (List<Integer> l : list) {
            List<Integer> t = new ArrayList(l);
            t.add(n);
            ret.add(t);
        }
        return ret;
    }
}
//leetcode submit region end(Prohibit modification and deletion