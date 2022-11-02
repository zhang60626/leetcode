import java.util.HashSet;
import java.util.Set;

class Solution {
    char[] gene = new char[] {'A', 'C', 'G', 'T'};
    
    public int minMutation(String start, String end, String[] bank) {
        Map<String, Boolean> map = new HashMap();
        
        for (String s : bank) map.put(s, false);
        map.put(start, false);
        
        if (!map.containsKey(end)) return -1;
        
        return dfs(map, start, end);
    }
    
    private int dfs(Map<String, Boolean> map, String curr, String target) {
        if (!map.containsKey(curr) || map.get(curr)) return -1;
        
        map.put(curr, true);       
        boolean eq = true;
        for (int i = 0; i < curr.length(); i++) {
            if (curr.charAt(i) != target.charAt(i)) eq = false;

            StringBuilder sb = new StringBuilder(curr);
            for (int j = 0; j < 4; j++) {
                if (curr.charAt(i) == gene[j]) continue;
                sb.setCharAt(i, gene[j]);
                int ret = dfs(map, sb.toString(), target);
                if (ret != -1) return ret + 1;
            }
        }
        map.put(curr, false);
        return eq ? 0 : -1;
    }
}
