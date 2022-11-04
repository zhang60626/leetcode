class Solution {
    public int longestPalindrome(String[] words) {
        int[][] arr = new int[26][26];
        int length = 0;
        
        for (String word : words) {
            arr[word.charAt(0) - 'a'][word.charAt(1) - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            for (int j = i + 1; j < 26; j++) {
                length += Math.min(arr[i][j], arr[j][i]) * 4;
            }
        }
        
        boolean hasSinglePalindrome = false;
        for (int i = 0; i < 26; i++) {
            if (arr[i][i] % 2 == 1) hhasSinglePalindrom = true;
            length += (arr[i][i] / 2) * 4;
        }
        
        return  hasSinglePalindrome ? length + 2 : length;
    }
}
