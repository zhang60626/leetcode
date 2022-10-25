
class Solution {
    private int[][] direction = {{-1, -1}, {-1, 0}, {-1, 1},
                                 {0, -1}, {0, 0}, {0, 1},
                                 {1, -1}, {1, 0}, {1, 1}};
    private final int N = 9;
    
    public void solveSudoku(char[][] board) {
        backtrace(board, 0, 0);
    }

    private boolean backtrace(char[][] board, int row, int col) {
        if (col == N) {
            col = 0;
            row++;
        }      
        if (row == N) return true;
        
        if (board[row][col] != '.') return backtrace(board, row, col + 1);
        
        for (char c = '1'; c <= '9'; c++) {
            board[row][col] = c;
            if (check(board, row, col)) {
                if (backtrace(board, row, col + 1)) return true;
            }
        }
        board[row][col] = '.';
        
        return false;
    }

    private boolean check(char[][] board, int row, int col) {
        int crow = getCenterCoord(row);
        int ccol = getCenterCoord(col);
        return checkRow(board, row) && checkCol(board, col) && checkGrid(board, crow, ccol);
    }
    
    // get center coordination
    private int getCenterCoord(int i) {
        if (i < 3) return 1;
        else if (i >= 6) return 7;
        else return 4;
    }

    private boolean checkRow(char[][] board, int row) {
        Set<Character> set = new HashSet<>();

        for (int i = 0; i < N; i++) {
            if (board[row][i] == '.') continue;
            if (set.contains(board[row][i])) return false;
            else set.add(board[row][i]);
        }

        return true;
    }

    private boolean checkCol(char[][] board, int col) {
        Set<Character> set = new HashSet();

        for (int i = 0; i < N; i++) {
            if (board[i][col] == '.') continue;
            if (set.contains(board[i][col])) return false;
            else set.add(board[i][col]);
        }

        return true;
    }

    // (row, col) must be coordination of the ceter of grid
    private boolean checkGrid(char[][] board, int row, int col) {
        Set<Character> set = new HashSet();

        for (int i = 0; i < N; i++) {
            int newRow = row + direction[i][0];
            int newCol = col + direction[i][1];
            if (board[newRow][newCol] == '.') continue;
            if (set.contains(board[newRow][newCol])) return false;
            else set.add(board[newRow][newCol]);
        }

        return true;
    }
}
