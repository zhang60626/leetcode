//You are given an array coordinates, coordinates[i] = [x, y], where [x, y] 
//represents the coordinate of a point. Check if these points make a straight line in 
//the XY plane. 
//
// 
//
// 
// Example 1: 
//
// 
//
// 
//Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
//Output: true
// 
//
// Example 2: 
//
// 
//
// 
//Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
//Output: false
// 
//
// 
// Constraints: 
//
// 
// 2 <= coordinates.length <= 1000 
// coordinates[i].length == 2 
// -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4 
// coordinates contains no duplicate point. 
// 
//
// Related Topics Array Math Geometry 👍 1086 👎 161


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
    public boolean checkStraightLine(int[][] coordinates) {
        if (coordinates[0][0] == coordinates[1][0]) {
            int x = coordinates[0][0];
            for (int[] p : coordinates) {
                if (p[0] == x) continue;
                return false;
            }
            return true;
        }
        double slope = 1.0 * (coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
        for (int i = 0; i < coordinates.length - 1; i++) {
            if (coordinates[i][0] == coordinates[i + 1][0]) return false;
            double t = 1.0 * (coordinates[i + 1][1] - coordinates[i][1]) / (coordinates[i + 1][0] - coordinates[i][0]);
            if (Math.abs(t - slope) < 0.00001) continue;
            return false;
        }
        return true;
    }
}
//leetcode submit region end(Prohibit modification and deletion)
