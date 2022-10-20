class Solution {
    public int lengthOfLastWord(String s) {
        String[] ss = s.split(" ");
        for (int i = ss.length - 1; i >= 0; i--) {
            if (!ss[i].isEmpty()) return ss[i].length();
        }
        
        return 0;
    }
}
