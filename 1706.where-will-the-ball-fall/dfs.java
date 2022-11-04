class Solution {
    public int[] findBall(int[][] grid) {
        int[] answer = new int[grid[0].length];
        
        for (int i = 0; i < grid[0].length; i++) {
            answer[i] = dfs(grid, 0, i);
        }
        
        return answer;
    }
    
    private int dfs(int[][] grid, int row, int col) {
        if (row == grid.length) return col;
        
        int nextCol = col + grid[row][col];
        
        if (nextCol < 0 || 
            nextCol >= grid[0].length ||
            grid[row][col] != grid[row][nextCol]) {
            return -1;
        }
        
        return dfs(grid, row + 1, nextCol);
    }
}
