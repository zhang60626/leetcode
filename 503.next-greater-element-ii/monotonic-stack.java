class Solution {
    public int[] nextGreaterElements(int[] nums) {
        if (nums.length == 1) return new int[] {-1};
        
        Deque<Integer> monoStack = new ArrayDeque();
        int[] answer = new int[nums.length];
        Arrays.fill(answer, -1);
        
        monoStack.push(0);
        int i = 1;
        while (!monoStack.isEmpty()) {
            while (!monoStack.isEmpty()) {
                int idx = monoStack.peek();
                if (idx == i || monoStack.size() > nums.length) {
                    return answer;
                }
                if (nums[idx] < nums[i]) {
                    answer[idx] = nums[i];
                    monoStack.pop();
                } else break;
            }
            monoStack.push(i);
            i++;
            if (i >= nums.length) i = 0;
        }
        
        return answer;
    }
}
