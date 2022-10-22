class Solution {
    // bi-direction map solution
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        List<String> ret = new LinkedList();
        
        for (String s : words) {
            if (s.length() != pattern.length()) continue;
            
            // use bi-directional map
            Map<Character, Character> map1 = new HashMap();
            Map<Character, Character> map2 = new HashMap();
            Boolean match = true;
            
            for (int i = 0; i < s.length(); i++) {
                if (map1.containsKey(pattern.charAt(i)) && map2.containsKey(s.charAt(i))) {
                    if (map1.get(pattern.charAt(i)) != s.charAt(i) || 
                        map2.get(s.charAt(i)) != pattern.charAt(i)) {
                        match = false;
                        break;
                    }
                } else if (!map1.containsKey(pattern.charAt(i)) &&
                           !map2.containsKey(s.charAt(i))) {
                    map1.put(pattern.charAt(i), s.charAt(i));
                    map2.put(s.charAt(i), pattern.charAt(i));
                } else {
                    match = false;
                    break;
                }
            }
            
            if (match) ret.add(s);
        }
        
        return ret;
    }
}
