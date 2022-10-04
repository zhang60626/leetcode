//In an alien language, surprisingly, they also use English lowercase letters, 
//but possibly in a different order. The order of the alphabet is some permutation 
//of lowercase letters. 
//
// Given a sequence of words written in the alien language, and the order of 
//the alphabet, return true if and only if the given words are sorted 
//lexicographically in this alien language. 
//
// 
// Example 1: 
//
// 
//Input: words = ["hello","leetcode"], order = "hlabcdefgijkmnopqrstuvwxyz"
//Output: true
//Explanation: As 'h' comes before 'l' in this language, then the sequence is 
//sorted.
// 
//
// Example 2: 
//
// 
//Input: words = ["word","world","row"], order = "worldabcefghijkmnpqstuvxyz"
//Output: false
//Explanation: As 'd' comes after 'l' in this language, then words[0] > words[1]
//, hence the sequence is unsorted.
// 
//
// Example 3: 
//
// 
//Input: words = ["apple","app"], order = "abcdefghijklmnopqrstuvwxyz"
//Output: false
//Explanation: The first three characters "app" match, and the second string is 
//shorter (in size.) According to lexicographical rules "apple" > "app", because 
//'l' > '∅', where '∅' is defined as the blank character which is less than any 
//other character (More info).
// 
//
// 
// Constraints: 
//
// 
// 1 <= words.length <= 100 
// 1 <= words[i].length <= 20 
// order.length == 26 
// All characters in words[i] and order are English lowercase letters. 
// 
//
// Related Topics Array Hash Table String 👍 3105 👎 989


import java.util.HashMap;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < order.length(); i++) {
            map.put(order.charAt(i), i);
        }
        for (int i = 0; i < words.length - 1; i++) {
            if (!helper(words[i], words[i + 1], map)) return false;
        }
        return true;
    }

    private boolean helper(String s1, String s2, Map<Character, Integer> map) {
        int p1 = 0;
        int p2 = 0;
        while (p1 < s1.length() && p2 < s2.length()) {
            if (map.get(s1.charAt(p1)) == map.get(s2.charAt(p2))) {
                p1++;
                p2++;
                continue;
            }
            if (map.get(s1.charAt(p1)) > map.get(s2.charAt(p2))) return false;
            else return true;
        }
        if (p1 < s1.length()) return false;
        else return true;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
