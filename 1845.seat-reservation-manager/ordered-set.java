class SeatManager {
    TreeSet<Integer> set;
    int curr;
    
    public SeatManager(int n) {
        set = new TreeSet();
        curr = 0;
    }
    
    public int reserve() {
        return set.isEmpty() ? ++curr : set.pollFirst();
    }
    
    public void unreserve(int seatNumber) {
        set.add(seatNumber);
    }
}

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager obj = new SeatManager(n);
 * int param_1 = obj.reserve();
 * obj.unreserve(seatNumber);
 */