//You are given an integer array nums. You are initially positioned at the 
//array's first index, and each element in the array represents your maximum jump 
//length at that position. 
//
// Return true if you can reach the last index, or false otherwise. 
//
// 
// Example 1: 
//
// 
//Input: nums = [2,3,1,1,4]
//Output: true
//Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
// 
//
// Example 2: 
//
// 
//Input: nums = [3,2,1,0,4]
//Output: false
//Explanation: You will always arrive at index 3 no matter what. Its maximum 
//jump length is 0, which makes it impossible to reach the last index.
// 
//
// 
// Constraints: 
//
// 
// 1 <= nums.length <= 10⁴ 
// 0 <= nums[i] <= 10⁵ 
// 
//
// Related Topics Array Dynamic Programming Greedy 👍 13319 👎 703


import java.util.Arrays;
import java.util.Iterator;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public boolean canJump(int[] nums) {
        int right = nums.length - 1;

        for (int left = nums.length - 2; left >= 0; left--) {
            if (nums[left] >= right - left) right = left;
        }
        return right == 0;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
