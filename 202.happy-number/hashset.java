class Solution {
    public boolean isHappy(int n) {
        Set<Integer> nset = new HashSet();
        
        int num = n;
        while (true) {
            if (nset.contains(num)) return false;
            nset.add(num);
            
            int sum = 0;
            while (num > 0) {
                int tmp = num % 10;
                sum = sum + tmp * tmp;
                num /= 10;
            }
            
            if (sum == 1) return true;
            num = sum;
        }
    }
}