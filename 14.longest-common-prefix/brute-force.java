class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) return "";
        
        StringBuilder sb = new StringBuilder();
        
        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0].charAt(i);
            for (int j = 1; j < strs.length; j++) {
                if (i < strs[j].length() && strs[j].charAt(i) == c) continue;
                else return sb.toString();
            }
            sb.append(c);
        }
        
        return sb.toString();
    }
}
