
class Solution {
    private int[][] direction = {{-1, -1}, {-1, 0}, {-1, 1},
                                 {0, -1}, {0, 0}, {0, 1},
                                 {1, -1}, {1, 0}, {1, 1}};

    public void solveSudoku(char[][] board) {
        backtrace(board, 0, 0);
    }

    private boolean backtrace(char[][] board, int row, int col) {
        for (int i = row; i < 9; i++) {
            int j = 0;
            if (i == row) j = col;
            for (; j < 9; j++) {
                if (board[i][j] != '.') continue;
                int crow = getCenterCoord(i);
                int ccol = getCenterCoord(j);
                // try
                int count = 0;
                for (int k = 0; k < 9; k++) {
                    board[i][j] = (char)('1' + k);
                    if (checkRow(board, i) && checkCol(board, j) && checkGrid(board, crow, ccol)) {
                        if (backtrace(board, i, j)) return true;
                        else count++;
                    } else count++;
                }
                if (count == 9) {
                    board[i][j] = '.';
                    return false;
                }
            }
        }
        return true;
    }
    /*
["5","3","1","2","7","4","6","9","9"],
["6","2","4","1","9","5","3","9","9"],
["9","9","8","9","9","9","9","6","9"],
["8","1","2","5","6","9","4","9","3"],
["4","5","6","8","9","3","9","9","1"],
["7","9","3","9","2","9","9","9","6"],
["1","6","5","9","9","9","2","8","9"],
["2","9","9","4","1","9","9","9","5"],
["9","9","9","9","8","9","9","7","9"]
     */

    // get center coordination
    private int getCenterCoord(int i) {
        if (i < 3) return 1;
        else if (i >= 6) return 7;
        else return 4;
    }

    private boolean checkRow(char[][] board, int row) {
        Set<Character> set = new HashSet<>();

        for (int i = 0; i < 9; i++) {
            if (board[row][i] == '.') continue;
            if (set.contains(board[row][i])) return false;
            else set.add(board[row][i]);
        }

        return true;
    }

    private boolean checkCol(char[][] board, int col) {
        Set<Character> set = new HashSet();

        for (int i = 0; i < 9; i++) {
            if (board[i][col] == '.') continue;
            if (set.contains(board[i][col])) return false;
            else set.add(board[i][col]);
        }

        return true;
    }

    // (row, col) must be coordination of the ceter of grid
    private boolean checkGrid(char[][] board, int row, int col) {
        Set<Character> set = new HashSet();

        for (int i = 0; i < 9; i++) {
            int newRow = row + direction[i][0];
            int newCol = col + direction[i][1];
            if (board[newRow][newCol] == '.') continue;
            if (set.contains(board[newRow][newCol])) return false;
            else set.add(board[newRow][newCol]);
        }

        return true;
    }
}
