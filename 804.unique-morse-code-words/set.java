class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        int n = words.length;
        String[] MORSE = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",
            ".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        Set<String> set = new HashSet();
        
        for (int i = 0; i < n; i++) {
            StringBuilder sb = new StringBuilder();
            for (char c : words[i].toCharArray()) {
                sb.append(MORSE[c - 'a']);
            }
            set.add(sb.toString());
        }
        
        return set.size();
    }
}
