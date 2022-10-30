class MyCalendar {
    private List<int[]> events;
    
    public MyCalendar() {
        events = new ArrayList();
    }
    
    // time complexity: o(n). n: number of events in calendar
    public boolean book(int start, int end) {
        for (int[] arr : events) {
            if ((start <= arr[0] && arr[0] < end) ||
                (start < arr[1] && arr[1] <= end) ||
                (arr[0] <= start && end <= arr[1])){
                return false;
            }
        }
        events.add(new int[] {start, end});
        return true;
    }
}

// 
/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * boolean param_1 = obj.book(start,end);
 */