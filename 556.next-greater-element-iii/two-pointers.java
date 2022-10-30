class Solution {
    public int nextGreaterElement(int n) {
        char[] num = String.valueOf(n).toCharArray();
        int ret;
        
        int pos;
        for (pos = num.length - 1; pos > 0; pos--) {
            if (num[pos - 1] < num[pos]) break;
        }
        if (pos == 0) return -1;
        else pos = pos - 1;
        
        int d = -1;
        for (int i = pos + 1; i < num.length; i++) {
            if (num[i] >  num[pos]) {
                if (d == -1) d = i;
                else if (num[i] < num[d]) d = i;
            }
        }
        if (d == -1) return -1;
        char t = num[pos];  // swap
        num[pos] = num[d];
        num[d] = t;

        Arrays.sort(num, pos + 1, num.length);
        
        try {
            ret = Integer.parseInt(String.valueOf(num));

        } catch (NumberFormatException e) {
            return -1;
        }
                
        return ret;
    }
}
