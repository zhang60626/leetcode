class RandomizedSet {
    private Map<Integer, Integer> map;
    private List<Integer> elements;
    private Random rand;
    
    public RandomizedSet() {
        map = new HashMap();
        elements = new ArrayList();
        rand = new Random();
    }
    
    public boolean insert(int val) {
        if (map.containsKey(val)) return false;
        map.put(val, elements.size());
        elements.add(val);
        return true;
    }
    
    public boolean remove(int val) {
        if (!map.containsKey(val)) return false;
        int n = elements.size();
        int valLoc = map.get(val);
        if (valLoc == n - 1) {
            elements.remove(n - 1);
            map.remove(val);
            return true;
        }
        map.put(elements.get(n - 1), valLoc);
        elements.set(valLoc, elements.get(n - 1));
        elements.remove(n - 1);
        map.remove(val);
        return true;
    }
    
    public int getRandom() {
        return elements.get(rand.nextInt(elements.size()));
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * boolean param_1 = obj.insert(val);
 * boolean param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */