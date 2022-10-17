//Given two strings needle and haystack, return the index of the first 
//occurrence of needle in haystack, or -1 if needle is not part of haystack. 
//
// 
// Example 1: 
//
// 
//Input: haystack = "sadbutsad", needle = "sad"
//Output: 0
//Explanation: "sad" occurs at index 0 and 6.
//The first occurrence is at index 0, so we return 0.
// 
//
// Example 2: 
//
// 
//Input: haystack = "leetcode", needle = "leeto"
//Output: -1
//Explanation: "leeto" did not occur in "leetcode", so we return -1.
// 
//
// 
// Constraints: 
//
// 
// 1 <= haystack.length, needle.length <= 10⁴ 
// haystack and needle consist of only lowercase English characters. 
// 
//
// Related Topics Two Pointers String String Matching 👍 574 👎 42


import java.util.ArrayList;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    // KMP algorith
    public int strStr(String string, String pattern) {
        int[] pm = getPm(pattern);

        int i = 0;
        int j = 0;
        while (i < string.length()) {
            if (string.charAt(i) == pattern.charAt(j)) { // match
                i++;
                j++;
                if (j == pattern.length()) { // full match
                    return i - j; // return index
                }
            } else { // mismatch
                if (j > 0) j = pm[j - 1];
                else i++;
            }
        }
        return -1; // no match
    }

    // compute Partial Match table
    private int[] getPm(String pattern) {
        int[] pm = new int[pattern.length()];
        for (int i = 1; i < pm.length; i++) {
            for (int j = 0; j < i; j++) {
                String prefix = pattern.substring(0, j + 1);
                String suffix = pattern.substring(i - j, i + 1);
                if (prefix.equals(suffix)) {
                    pm[i] = prefix.length();
                }
            }
        }
        return pm;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
