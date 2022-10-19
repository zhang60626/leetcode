class Solution {
    // KMP algorithm
    public boolean repeatedSubstringPattern(String s) {
        int len = s.length();
        
        int n = 0;
        for (int i = 1; i < len; i++) {
            String prefix = s.substring(0, i);
            String suffix = s.substring(len - i, len);
            if (prefix.equals(suffix)) n = i;
        }
        
        return n > 0 && len % (len - n) == 0;
    }
}
