class Solution {
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        int maxTime  = Integer.MIN_VALUE;
        for (int i = 0; i < informTime.length; i++) {
            if (informTime[i] != 0) continue;
            
            int currTime = 0;           
            for (int idx = manager[i]; idx != -1; idx = manager[idx]) {
                currTime += informTime[idx];
            }
            
            maxTime = Math.max(maxTime, currTime);
        }
        
        return maxTime;
    }
}
