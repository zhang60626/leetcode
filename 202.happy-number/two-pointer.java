class Solution {
    public boolean isHappy(int n) {
        int fast = n;
        int slow = n;
        while (true) {
            fast = getNext(getNext(fast));
            slow = getNext(slow);
            if (slow == fast) break;
        }
        return fast == 1;
    }
    
    public int getNext(int n) {
        int sum = 0;
        while (n > 0) {
            int tmp = n % 10;
            sum = sum + tmp * tmp;
            n /= 10;
        }
        return sum;
    }
}
