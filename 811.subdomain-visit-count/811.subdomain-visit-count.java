class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        List<String> ret = new ArrayList();
        Map<String, Integer> map = new HashMap();
        
        for (String s : cpdomains) {
            String[] ss = s.split(" ");
            int count = Integer.parseInt(ss[0]);
            map.put(ss[1], map.getOrDefault(ss[1], 0) + count);
            
            // split() takes a regular expression, not a separator string to split by
            // the regular expression "." means "any single character"
            // "\." escape "." in regex. "\\" escape "\" in Java.
            String[] ds = ss[1].split("\\.");
            if (ds.length == 2) {
                map.put(ds[1], map.getOrDefault(ds[1], 0) + count);
            } else if (ds.length == 3) {
                map.put(ds[2], map.getOrDefault(ds[2], 0) + count);
                map.put(ds[1] + "." + ds[2], map.getOrDefault(ds[1] + "." + ds[2], 0) + count);
            }
        }
        
        for (Map.Entry<String, Integer> e : map.entrySet()) {
            ret.add(e.getValue() + " " + e.getKey());
        }
        
        return ret;
    }
}
