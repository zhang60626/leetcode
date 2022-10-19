class Solution {
    public boolean repeatedSubstringPattern(String s) {
        int len = s.length();
        for (int i = 1; i <= len / 2; i++) {
            if (len % i != 0) continue;
            String sub = s.substring(0, i);
            // i == sub.length()
            int n = i;
            boolean mark = true;
            while (n < len && i + n <= len) {
                if (!sub.equals(s.substring(n, n + i))) {
                    mark = false;
                    break;
                }
                n += i;
            }
            if (mark) return true;
        }
        return false;
    }
}
