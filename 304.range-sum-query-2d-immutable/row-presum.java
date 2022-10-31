class NumMatrix {
    private int[][] presum;
    private int m;
    private int n;
    
    public NumMatrix(int[][] matrix) {
        m = matrix.length;
        n = matrix[0].length;
        presum = new int[m][n + 1];
        
        for (int i = 0; i < m; i++) {
            for (int j = 1; j < n + 1; j++) {
                presum[i][j] = presum[i][j - 1] + matrix[i][j - 1];
            }
        }
    }
    
    public int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; i++) {
            sum += (presum[i][col2 + 1] - presum[i][col1]);
        }
        return sum;
    }
}

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */