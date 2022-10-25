class Solution {
    public boolean findRotation(int[][] mat, int[][] target) {
        if (isEqual(mat, target)) return true;
        for (int i = 0; i < 3; i++) {
            rotate(mat);
            if (isEqual(mat, target)) return true;
        }
        
        return false;
    }
    
    private boolean isEqual(int[][] mat, int[][] target) {
        int n = mat.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] != target[i][j]) return false;
            }
        }
        return true;
    }

    private void rotate(int[][] mat) {
        int n = mat.length;
        for (int i = 0; i < (n + 1) / 2; i++) {
            for (int j = 0; j < n / 2; j++) {
                int temp = mat[i][j];
                mat[i][j] = mat[n - j - 1][i];
                mat[n - j - 1][i] = mat[n - i - 1][n - j - 1];
                mat[n - i - 1][n - j - 1] = mat[j][n - i - 1];
                mat[j][n - i - 1] = temp;
            }
        }
            
    }
}
