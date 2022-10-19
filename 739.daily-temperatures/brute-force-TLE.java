class Solution {
    // time complexity o(n^2)
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        int[] answer = new int[n];
        
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (temperatures[i] < temperatures[j]) {
                    answer[i] = j - i;
                    break;
                }
            }
        }
        
        return answer;
    }
}
