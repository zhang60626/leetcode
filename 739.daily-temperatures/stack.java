import java.util.ArrayDeque;

class Solution {
    // time complexity o(n)
    // space complexity o(n)
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        Deque<Integer> stack = new ArrayDeque();
        Deque<Integer> index = new ArrayDeque();
        int[] answer = new int[n];

        int i = 1;
        stack.push(temperatures[0]);
        index.push(0);
        while (!stack.isEmpty() && i < n) {
            while (!stack.isEmpty() && temperatures[i] > stack.peek()) {
                answer[index.peek()] = i - index.peek();
                stack.pop();
                index.pop();
            }
            stack.push(temperatures[i]);
            index.push(i);
            i++;
        }
        
        return answer;
    }
}
