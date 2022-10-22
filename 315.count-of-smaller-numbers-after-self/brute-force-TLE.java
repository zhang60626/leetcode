class Solution {
    public List<Integer> countSmaller(int[] nums) {
        List<Integer> answer = new ArrayList();
        
        for (int i = 0; i < nums.length; i++) {
            int count = 0;
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[j] < nums[i]) count++;
            }
            answer.add(count);
        }
        
        return answer;
    }
}
