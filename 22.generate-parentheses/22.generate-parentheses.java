//Given n pairs of parentheses, write a function to generate all combinations 
//of well-formed parentheses. 
//
// 
// Example 1: 
// Input: n = 3
//Output: ["((()))","(()())","(())()","()(())","()()()"]
// 
// Example 2: 
// Input: n = 1
//Output: ["()"]
// 
// 
// Constraints: 
//
// 
// 1 <= n <= 8 
// 
//
// Related Topics String Dynamic Programming Backtracking 👍 15471 👎 596


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    StringBuilder sb;
    List<String> output;

    public List<String> generateParenthesis(int n) {
        sb = new StringBuilder();
        output = new LinkedList();

        backtrace(n, 0, 0);
        return output;
    }

    private void backtrace(int n, int lnum, int rnum) {
        if (sb.length() == 2 * n && lnum == n && rnum == n) {
            output.add(sb.toString());
            return;
        }

        if (lnum <= n) { // put open parenthesis first
            sb.append('(');
            backtrace(n, lnum + 1, rnum);
            sb.deleteCharAt(sb.length() - 1);
        }
        if (rnum < lnum) { // make sure parentheses well-formed
            sb.append(')');
            backtrace(n, lnum, rnum + 1);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
