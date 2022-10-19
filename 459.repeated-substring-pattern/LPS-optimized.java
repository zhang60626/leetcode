// see https://leetcode.com/problems/repeated-substring-pattern/discuss/1694256/Java-KMP-solution-with-explanation
class Solution {
    // KMP algorithm
    public boolean repeatedSubstringPattern(String s) {
        int len = s.length();
        int[] lps = new int[len];
        int i = 1;
        int prev = 0;
        
        while (i < len) {
            if (s.charAt(i) == s.charAt(prev)) {
                prev++;
                lps[i] = prev;
                i++;
            } else if (prev == 0) {
                lps[i] = 0;
                i++;
            } else {
                prev = lps[prev - 1];
            }
        }
        
        return lps[len - 1] > 0 && len % (len - lps[len - 1]) == 0;
    }
}
