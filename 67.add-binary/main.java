class Solution {
    public String addBinary(String a, String b) {
        int n1 = a.length() - 1;
        int n2 = b.length() - 1;
        StringBuilder sb = new StringBuilder();
        
        int carry = 0;
        while (n1 >= 0 && n2 >= 0) {
            int num1 = a.charAt(n1) - '0';
            int num2 = b.charAt(n2) - '0';
            sb.append((num1 + num2 + carry) % 2);
            carry = (num1 + num2 + carry) / 2;
            n1--;
            n2--;
        }
        while (n1 >= 0) {
            int num = a.charAt(n1) - '0';
            sb.append((num + carry) % 2);
            carry = (num + carry) / 2;
            n1--;
        }
        while (n2 >= 0) {
            int num = b.charAt(n2) - '0';
            sb.append((num + carry) % 2);
            carry = (num + carry) / 2;
            n2--;
        }
        if (carry != 0) sb.append(carry);
        
        return sb.reverse().toString();
    }
}
