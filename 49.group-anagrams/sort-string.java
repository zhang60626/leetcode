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
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List> ret = new HashMap<>();
        for (String s : strs) {
            char[] ca = s.toCharArray();
            Arrays.sort(ca);
            String key = String.valueOf(ca);
            if (!ret.containsKey(key)) ret.put(key, new ArrayList());
            ret.get(key).add(s);
        }
        return new ArrayList(ret.values());
    }
}
//leetcode submit region end(Prohibit modification and deletion)
