//Given a string containing digits from 2-9 inclusive, return all possible 
//letter combinations that the number could represent. Return the answer in any order. 
//
//
// A mapping of digits to letters (just like on the telephone buttons) is given 
//below. Note that 1 does not map to any letters. 
// 
// 
// Example 1: 
//
// 
//Input: digits = "23"
//Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
// 
//
// Example 2: 
//
// 
//Input: digits = ""
//Output: []
// 
//
// Example 3: 
//
// 
//Input: digits = "2"
//Output: ["a","b","c"]
// 
//
// 
// Constraints: 
//
// 
// 0 <= digits.length <= 4 
// digits[i] is a digit in the range ['2', '9']. 
// 
//
// Related Topics Hash Table String Backtracking 👍 12846 👎 766


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    String[] map = {"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};
    List<String> output;
    StringBuilder sb;

    public List<String> letterCombinations(String digits) {
        output = new LinkedList();
        sb = new StringBuilder();

        if (!digits.isEmpty()) backtrace(digits, 0);

        return output;
    }

    void backtrace(String digits, int idx) {
        if (sb.length() == digits.length()) {
            output.add(sb.toString());
            return;
        }

        int n = digits.charAt(idx) - '0';
        for (int i = 0; i < map[n].length(); i++) {
            sb.append(map[n].charAt(i));
            backtrace(digits, idx + 1);
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}
//leetcode submit region end(Prohibit modification and deletion)
