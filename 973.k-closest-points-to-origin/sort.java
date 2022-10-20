class Solution {
    public int[][] kClosest(int[][] points, int k) {
        int[][] output = new int[k][2];
        
        Arrays.sort(points, (p1, p2) -> (p1[0] * p1[0] + p1[1] * p1[1]) - (p2[0] * p2[0] + p2[1] * p2[1]));
        
        for (int i = 0; i < k; i++) {
            output[i] = points[i];
        }
        
        return output;
    }
}
