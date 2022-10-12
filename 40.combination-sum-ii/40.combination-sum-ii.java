//Given a collection of candidate numbers (candidates) and a target number (
//target), find all unique combinations in candidates where the candidate numbers sum 
//to target. 
//
// Each number in candidates may only be used once in the combination. 
//
// Note: The solution set must not contain duplicate combinations. 
//
// 
// Example 1: 
//
// 
//Input: candidates = [10,1,2,7,6,1,5], target = 8
//Output: 
//[
//[1,1,6],
//[1,2,5],
//[1,7],
//[2,6]
//]
// 
//
// Example 2: 
//
// 
//Input: candidates = [2,5,2,1,2], target = 5
//Output: 
//[
//[1,2,2],
//[5]
//]
// 
//
// 
// Constraints: 
//
// 
// 1 <= candidates.length <= 100 
// 1 <= candidates[i] <= 50 
// 1 <= target <= 30 
// 
//
// Related Topics Array Backtracking 👍 7058 👎 174


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    List<List<Integer>> output;
    List<Integer> curr;

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        output = new ArrayList();
        curr = new ArrayList();

        Arrays.sort(candidates);
        backtrace(candidates, target, 0, 0);
        return output;
    }

    private void backtrace(int[] candidates, int target, int sum, int start) {
        if (sum > target) return;
        if (sum == target) {
            output.add(new ArrayList(curr));
            return;
        }

        for (int i = start; i < candidates.length; i++) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            curr.add(candidates[i]);
            backtrace(candidates, target, sum + candidates[i], i + 1);
            curr.remove(curr.size() - 1);
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
