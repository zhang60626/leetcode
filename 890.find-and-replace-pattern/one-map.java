class Solution {
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> ret = new LinkedList();
        
        for (String s : words) {
            if (match(s, pattern)) ret.add(s);
        }
        
        return ret;
    }
    
    private boolean match(String word, String pattern) {
        if (word.length() != pattern.length()) return false;
        
        Map<Character, Character> map = new HashMap();
        for (int i = 0; i < word.length(); i++) {
            char w = word.charAt(i);
            char p = pattern.charAt(i);
            if (!map.containsKey(p)) map.put(p, w);
            if (map.get(p) != w) return false;
        }
        
        boolean[] seen = new boolean[26];
        for (char c : map.values()) {
            if (seen[c - 'a']) return false;
            seen[c - 'a'] = true;
        }
        
        return true;
    }
}
