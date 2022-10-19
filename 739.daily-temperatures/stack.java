import java.util.ArrayDeque;

class Solution {
    // time complexity o(n)
    // space complexity o(n)
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        Deque<Integer> stack = new ArrayDeque();
        int[] answer = new int[n];
        stack.push(0);

        for (int i = 1; !stack.isEmpty() && i < n; i++) {
            while (!stack.isEmpty() && temperatures[i] > temperatures[stack.peek()]) {
                answer[stack.peek()] = i - stack.peek();
                stack.pop();
            }
            stack.push(i);
        }
        
        return answer;
    }
}
