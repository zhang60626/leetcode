//Given an n x n binary matrix grid, return the length of the shortest clear 
//path in the matrix. If there is no clear path, return -1. 
//
// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0
//)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that: 
//
// 
// All the visited cells of the path are 0. 
// All the adjacent cells of the path are 8-directionally connected (i.e., they 
//are different and they share an edge or a corner). 
// 
//
// The length of a clear path is the number of visited cells of this path. 
//
// 
// Example 1: 
// 
// 
//Input: grid = [[0,1],[1,0]]
//Output: 2
// 
//
// Example 2: 
// 
// 
//Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
//Output: 4
// 
//
// Example 3: 
//
// 
//Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
//Output: -1
// 
//
// 
// Constraints: 
//
// 
// n == grid.length 
// n == grid[i].length 
// 1 <= n <= 100 
// grid[i][j] is 0 or 1 
// 
//
// Related Topics Array Breadth-First Search Matrix 👍 4033 👎 169


//leetcode submit region begin(Prohibit modification and deletion)
import java.util.LinkedList;

class Solution {
    boolean[][] used;
    int count;
    int[][] direction = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int n;

    public int shortestPathBinaryMatrix(int[][] grid) {
        if (grid[0][0] == 1) return -1;

        n = grid.length;
        used = new boolean[n][n];
        count = 0;

        Queue<int[]> q = new LinkedList();
        q.offer(new int[]{0, 0});
        used[0][0] = true;

        while (!q.isEmpty()) {
            int size = q.size();
            count++;

            for (int i = 0; i < size; i++) {
                int[] cur = q.poll();

                if (cur[0] == n - 1 && cur[1] == n - 1) {
                    return count;
                }

                for (int j = 0; j < direction.length; j++) {
                    int newX = cur[0] + direction[j][0];
                    int newY = cur[1] + direction[j][1];
                    if (inArea(newX, newY) && !used[newX][newY] && grid[newX][newY] == 0) {
                        q.offer(new int[] {newX, newY});
                        used[newX][newY] = true;
                    }
                }
            }
        }

        return -1;
    }

    private boolean inArea(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < n;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
