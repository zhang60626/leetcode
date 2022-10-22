class Solution {
    public int[][] flipAndInvertImage(int[][] image) {
        int n = image.length;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n / 2; j++) {
                int t = image[i][j];
                image[i][j] = image[i][n - j - 1];
                image[i][n - j -1] = t;
            }    
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                image[i][j] = 1 -image[i][j];
            }
        }
        
        return image;
    }
}
