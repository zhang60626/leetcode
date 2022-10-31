class Solution {
    public boolean isToeplitzMatrix(int[][] matrix) {
        for (int i = 0; i < matrix[0].length - 1; i++) {
            if (!isSame(matrix, 0, i)) return false;
        }
        for (int i = 1; i < matrix.length; i++) {
            if (!isSame(matrix, i, 0)) return false;
        }

        return true;
    }
    
    private boolean inArea(int[][] matrix, int i, int j) {
        return 0 <= i && i < matrix.length && 0 <= j && j < matrix[0].length;
    }
    
    private boolean isSame(int[][] matrix, int row, int col) {
        int num = matrix[row][col];
        row++;
        col++;
        while (inArea(matrix, row, col)) {
            if (num != matrix[row][col]) return false;
            row++;
            col++;
        }
        return true;
    }
}