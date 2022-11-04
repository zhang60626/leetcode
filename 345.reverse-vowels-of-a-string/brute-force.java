import java.util.*;

class Solution {
    public String reverseVowels(String s) {
        Character[] cs = new Character[] {'a', 'A', 'o', 'O', 'e', 'E', 'i', 'I', 'u', 'U'};
        Set<Character> set = new HashSet(Arrays.asList(cs));
        List<Character> list = new ArrayList();

        for (char c : s.toCharArray()) {
            if (set.contains(c)) list.add(c);  
        }
        
        StringBuilder sb = new StringBuilder(s);
        for (int i = 0; i < sb.length(); i++) {
            if (set.contains(sb.charAt(i))) sb.setCharAt(i, list.remove(list.size() - 1));
        }

        return sb.toString();
    }
}
