import java.util.ArrayList;
import java.util.HashMap;
import java.util.PriorityQueue;

class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> map = new HashMap();
        Queue<String> pq = new PriorityQueue<>(
            (n1, n2) -> map.get(n1) == map.get(n2) ? n1.compareTo(n2) : map.get(n2) - map.get(n1));
        List<String> output = new ArrayList();
        
        for (String s : words) {
            map.put(s, map.getOrDefault(s, 0) + 1);
        }
        
        for (Map.Entry<String, Integer> e : map.entrySet()) {
            pq.add(e.getKey());
        }
        
        for (int i = 0; i < k; i++) {
            output.add(pq.poll());
        }
        
        return output;
    }
}
