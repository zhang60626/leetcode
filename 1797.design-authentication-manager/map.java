class AuthenticationManager {
    private Map<String, Integer> map;
    private int ttl;
    
    public AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
        map = new HashMap();
    }
    
    public void generate(String tokenId, int currentTime) {
        map.put(tokenId, currentTime + ttl);
    }
    
    public void renew(String tokenId, int currentTime) {
        if (map.containsKey(tokenId)) {
            if (map.get(tokenId) <= currentTime) map.remove(tokenId);
            else map.put(tokenId, currentTime + ttl);
        }
    }
    
    public int countUnexpiredTokens(int currentTime) {
        int count = 0;
        Iterator<Map.Entry<String, Integer>> it = map.entrySet().iterator();
        while (it.hasNext()) {
            Map.Entry<String, Integer> entry = it.next();
            if (entry.getValue() <= currentTime) it.remove();
            else count++;
        }
        return count;
    }
}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager obj = new AuthenticationManager(timeToLive);
 * obj.generate(tokenId,currentTime);
 * obj.renew(tokenId,currentTime);
 * int param_3 = obj.countUnexpiredTokens(currentTime);
 */