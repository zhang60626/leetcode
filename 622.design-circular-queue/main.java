class MyCircularQueue {
    private int[] elements;
    private int first;
    private int last;
    
    public MyCircularQueue(int k) {
        elements = new int[k + 1];
        first = 0;
        last = 0;
    }
    
    public boolean enQueue(int value) {
        if (isFull()) return false;
        elements[last % elements.length] = value;
        last = (last + 1) % elements.length;
        return true;
    }
    
    public boolean deQueue() {
        if (isEmpty()) return false;
        first = (first + 1) % elements.length;
        return true;
    }
    
    public int Front() {
        if (isEmpty()) return -1;
        return elements[first];
    }
    
    public int Rear() {
        if (isEmpty()) return -1;
        if (last == 0) return elements[elements.length - 1];
        else return elements[last - 1];
    }
    
    public boolean isEmpty() {
        return first == last;
    }
    
    public boolean isFull() {
        return (last + 1) % elements.length == first;
    }
}

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue obj = new MyCircularQueue(k);
 * boolean param_1 = obj.enQueue(value);
 * boolean param_2 = obj.deQueue();
 * int param_3 = obj.Front();
 * int param_4 = obj.Rear();
 * boolean param_5 = obj.isEmpty();
 * boolean param_6 = obj.isFull();
 */