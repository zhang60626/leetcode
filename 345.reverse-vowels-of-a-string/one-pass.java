
import java.util.*;

class Solution {
    public String reverseVowels(String s) {
        Character[] cs = new Character[] {'a', 'A', 'o', 'O', 'e', 'E', 'i', 'I', 'u', 'U'};
        Set<Character> set = new HashSet(Arrays.asList(cs));
        
        StringBuilder sb = new StringBuilder(s);
        int left = 0;
        int right = sb.length() - 1;
        while (left < right) {
            while (!set.contains(sb.charAt(left))) {
                left++;
                if (left >= sb.length()) break;
            }
            while (!set.contains(sb.charAt(right))) {
                right--;
                if (right < 0) break;
            }
            if (left < right) {
                char t = sb.charAt(left);
                sb.setCharAt(left, sb.charAt(right));
                sb.setCharAt(right, t);
            }
            left++;
            right--;
        }

        return sb.toString();
    }
}
