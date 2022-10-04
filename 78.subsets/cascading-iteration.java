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
import java.util.List;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    //  time complexity: o(n * 2^n)
    // space complexity: o(n * 2^n)
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ret = new ArrayList();
        ret.add(new ArrayList());

        for (int n : nums) {
            int size = ret.size();
            for (int i = 0; i < size; i++) {
                List<Integer> t = new ArrayList(ret.get(i));
                t.add(n);
                ret.add(t);
            }
        }
        return ret;
    }
}
//leetcode submit region end(Prohibit modification and deletion