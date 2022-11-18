class Solution {
    boolean[][] visited;
    int[][] direction = new int[][] {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    public boolean exist(char[][] board, String word) {
        int m = board.length;
        int n = board[0].length;
        visited = new boolean[m][n];
        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) return true;
            }
        }
        
        return false;
    }
    
    private boolean dfs(char[][] board, String word, int row, int col, int idx) {
        int m = board.length;
        int n = board[0].length;
        
        if (idx == word.length()) return true;
        if (row < 0 || row >= m || col < 0 || col >= n) return false;
        if (visited[row][col] || board[row][col] != word.charAt(idx)) return false;
        
        visited[row][col] = true;
        for (int i = 0; i < 4; i++) {
            if (dfs(board, word, row + direction[i][0], col + direction[i][1], idx + 1))
                return true;
        }
        visited[row][col] = false;
        
        return false;
    }
}
