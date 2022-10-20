class Solution {
    public int[][] kClosest(int[][] points, int k) {
        int[][] output = new int[k][2];
        
        Queue<int[]> pq = new PriorityQueue<int[]>(
            (p1, p2) -> (p1[0] * p1[0] + p1[1] * p1[1]) - (p2[0] * p2[0] + p2[1] * p2[1]));
        
        for (int[] p : points) {
            pq.add(p);    
        }
        
        for (int i = 0; i < k; i++) {
            output[i] = pq.poll();
        }
        
        return output;
    }
}
