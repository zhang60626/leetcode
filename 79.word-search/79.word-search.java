//Given an m x n grid of characters board and a string word, return true if 
//word exists in the grid. 
//
// The word can be constructed from letters of sequentially adjacent cells, 
//where adjacent cells are horizontally or vertically neighboring. The same letter 
//cell may not be used more than once. 
//
// 
// Example 1: 
// 
// 
//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
// "ABCCED"
//Output: true
// 
//
// Example 2: 
// 
// 
//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
// "SEE"
//Output: true
// 
//
// Example 3: 
// 
// 
//Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word =
// "ABCB"
//Output: false
// 
//
// 
// Constraints: 
//
// 
// m == board.length 
// n = board[i].length 
// 1 <= m, n <= 6 
// 1 <= word.length <= 15 
// board and word consists of only lowercase and uppercase English letters. 
// 
//
// 
// Follow up: Could you use search pruning to make your solution faster with a 
//larger board? 
//
// Related Topics Array Backtracking Matrix 👍 11137 👎 424


import java.util.Arrays;

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    int[][] direction = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    boolean[][] marked;

    public boolean exist(char[][] board, String word) {
        marked = new boolean[board.length][board[0].length];

        for (int i = 0; i < board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (backtrace(board, i, j, word, 0)) return true;
            }
        }
        return false;
    }

    private boolean backtrace(char[][] board, int x, int y, String word, int idx) {
        if (idx == word.length() - 1 && board[x][y] == word.charAt(idx)) return true;
        if (board[x][y] != word.charAt(idx)) return false;

        marked[x][y] = true;
        for (int i = 0; i < direction.length; i++) {
            int newX = x + direction[i][0];
            int newY = y + direction[i][1];
            if (inArea(newX, newY, board.length, board[0].length) && !marked[newX][newY]) {
                if (backtrace(board, newX, newY, word, idx + 1)) return true;
            }
        }
        marked[x][y] = false;
        return false;
    }

    private boolean inArea(int x, int y, int m, int n) {
        return x >= 0 && y >= 0 && x < m && y < n;
    }

}
//leetcode submit region end(Prohibit modification and deletion)
