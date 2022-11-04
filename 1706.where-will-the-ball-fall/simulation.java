class Solution {
    public int[] findBall(int[][] grid) {
        int[] answer = new int[grid[0].length];
        
        for (int i = 0; i < grid[0].length; i++) {
            answer[i] = helper(grid, i);
        }
        
        return answer;
    }
    
    private int helper(int[][] grid, int pos) {

        for (int i = 0; i < grid.length; i++) {
            int nextPos = pos + grid[i][pos];
        
            if (nextPos < 0 || 
                nextPos >= grid[0].length ||
                grid[i][pos] != grid[i][nextPos]) {
                return -1;
            }
            pos = nextPos;
        }
        
        return pos;
    }
}
