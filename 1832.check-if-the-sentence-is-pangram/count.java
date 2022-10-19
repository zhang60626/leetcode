class Solution {
    public boolean checkIfPangram(String sentence) {
        int[] count = new int[26];
        
        for (char c : sentence.toCharArray()) {
            count[c - 'a']++;
        }
        
        for (int num : count) {
            if (num == 0) return false;
        }
        
        return true;
    }
}