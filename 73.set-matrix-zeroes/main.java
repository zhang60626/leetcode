class Solution {
    int m;
    int n;
    boolean[][] marked;
        
    public void setZeroes(int[][] matrix) {
        m = matrix.length;
        n = matrix[0].length;
        marked = new boolean[m][n];
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (marked[i][j]) continue;
                if (matrix[i][j] == 0) {
                    marked[i][j] = true;
                    helper(matrix, i, j);
                }
            }
        }
    }
    
    private void helper(int[][] matrix, int row, int col) {
        for (int i = 0; i < m; i++) {
            if (matrix[i][col] == 0) continue;
            matrix[i][col] = 0;
            marked[i][col] = true;
        }
        for (int i = 0; i < n; i++) {
            if (matrix[row][i] == 0) continue;
            matrix[row][i] = 0;
            marked[row][i] = true;
        }
    }
}
