
class Solution {
    List<Integer> output;
    Boolean[][] used;
    int m;
    int n;
    int[][] direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int idx = 0;
    
    public List<Integer> spiralOrder(int[][] matrix) {
        m = matrix.length;
        n = matrix[0].length;
        output = new ArrayList();
        used = new Boolean[m][n];
        Arrays.stream(used).forEach(a -> Arrays.fill(a, false));
        
        dfs(matrix, 0, 0);
        
        return output;
    }
    
    private void dfs(int[][] matrix, int row, int col) {
        if (!inArea(row, col) || used[row][col]) {
            return;
        }
        
        output.add(matrix[row][col]);
        used[row][col] = true;
        
        for (int i = 0; i < 3; i++) {
            dfs(matrix, row + direction[idx][0], col + direction[idx][1]);        
            idx++;
            if (idx >= 4) idx = 0;
        }
    }
    
    private Boolean inArea(int row, int col) {
        return row >= 0 && col >= 0 && row < m && col < n;
    }
}
