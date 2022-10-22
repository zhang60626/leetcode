class Solution {
    public int uniqueMorseRepresentations(String[] words) {
        int n = words.length;
        String[] morse = new String[n];
        String[] map = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",
            ".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for (int i = 0; i < n; i++) {
            StringBuilder sb = new StringBuilder();
            for (char c : words[i].toCharArray()) {
                sb.append(map[c - 'a']);
            }
            morse[i] = sb.toString();
        }
        
        for (int i = 0; i < n; i++) {
            if (morse[i] == null) continue;
            for (int j = i + 1; j < n; j++) {
                if (morse[j] == null) continue;
                if (morse[i].equals(morse[j])) morse[j] = null;
            }
        }
        
        int count = 0;
        for (String s : morse) {
            if (s != null) count++;
        }
        
        return count;
    }
}
