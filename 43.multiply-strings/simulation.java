class Solution {
    public String multiply(String num1, String num2) {
        int n1 = num1.length();
        int n2 = num2.length();
        int[] sum = new int[n1 + n2 - 1];
        StringBuilder sb = new StringBuilder();
        
        for (int j = n2 - 1; j >= 0; j--) {
            for (int i = n1 - 1; i >= 0; i--) {
                sum[j + i] += ((num1.charAt(i) - '0') * (num2.charAt(j) - '0'));
            }
        }
        
        // deal with carry
        int carry = 0;
        for (int i = sum.length - 1; i >= 0; i--) {
            int t = (sum[i] + carry) / 10;
            sum[i] = (sum[i] + carry) % 10;
            carry = t;
        }
        
        if (carry != 0) sb.append(carry);
        for (int i = 0; i < sum.length; i++) {
            if (sb.isEmpty() && sum[i] == 0) continue;
            sb.append(sum[i]);
        }
        
        return sb.isEmpty() ? "0" : sb.toString();
    }
    
}
