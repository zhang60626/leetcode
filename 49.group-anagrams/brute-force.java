//Given an array of strings strs, group the anagrams together. You can return 
//the answer in any order. 
//
// An Anagram is a word or phrase formed by rearranging the letters of a 
//different word or phrase, typically using all the original letters exactly once. 
//
// 
// Example 1: 
// Input: strs = ["eat","tea","tan","ate","nat","bat"]
//Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// 
// Example 2: 
// Input: strs = [""]
//Output: [[""]]
// 
// Example 3: 
// Input: strs = ["a"]
//Output: [["a"]]
// 
// 
// Constraints: 
//
// 
// 1 <= strs.length <= 10⁴ 
// 0 <= strs[i].length <= 100 
// strs[i] consists of lowercase English letters. 
// 
//
// Related Topics Array Hash Table String Sorting 👍 11768 👎 369


import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        List<Map<Character, Integer>> anagrams = new ArrayList<>();
        for (String s : strs) {
            Map<Character, Integer> tmp = new HashMap<Character, Integer>();
            for (char c : s.toCharArray()) {
                if (tmp.containsKey(c)) {
                    tmp.put(c, tmp.get(c) + 1);
                } else {
                    tmp.put(c, 1);
                }
            }
            anagrams.add(tmp);
        }
        boolean[] grouped = new boolean[strs.length];
        List<List<String>> ret = new ArrayList<List<String>>();
        for (int i = 0; i < strs.length; i++) {
            if (grouped[i]) continue;
            List<String> ls = new ArrayList<>();
            ls.add(strs[i]);
            for (int j = i + 1; j < strs.length; j++) {
                if (grouped[j] || anagrams.get(i).size() != anagrams.get(j).size()) continue;
                if (anagrams.get(i).equals(anagrams.get(j))) {
                    ls.add(strs[j]);
                    grouped[j] = true;
                }
            }
            ret.add(ls);
        }
        return ret;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
