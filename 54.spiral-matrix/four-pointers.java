
class Solution {    
    public List<Integer> spiralOrder(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;
        List<Integer> output = new ArrayList();
        int direction = 0;
        int size = m * n;
        int right = n - 1;
        int bottom = m - 1;
        int left = 0;
        int top = 0;
        
        while (output.size() < size) {
            switch (direction) {
                case 0: // left to right
                    for (int i = left; i <= right; i++) output.add(matrix[top][i]);
                    top++;
                    direction = 1;
                    break;
                case 1: // top to bottom
                    for (int i = top; i <= bottom; i++) output.add(matrix[i][right]);
                    right--;
                    direction = 2;
                    break;
                case 2: // right to left
                    for (int i = right; i >= left; i--) output.add(matrix[bottom][i]);
                    bottom--;
                    direction = 3;
                    break;
                case 3 : // bottom to top
                    for (int i = bottom; i >= top; i--) output.add(matrix[i][left]);
                    left++;
                    direction = 0;
                    break;
            }
        }
        
        return output;
    }
}
