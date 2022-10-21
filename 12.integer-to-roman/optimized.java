class Solution {
    public String intToRoman(int num) { 
        StringBuilder sb = new StringBuilder();
        int[] value =  {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        String[] roman = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        
        for (int i = value.length - 1; i >= 0 && num > 0; i--) {
            while (num >= value[i]) {
                sb.append(roman[i]);
                num -= value[i];
            }
        }
        
        return sb.toString();
    }
}
