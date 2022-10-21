class Solution {
    public String intToRoman(int num) { 
        StringBuilder sb = new StringBuilder();
        Map<Integer, String> map = new HashMap();
        int[] key =  {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 20, 30, 40, 50, 60, 70, 80, 90, 
                      100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 2000, 3000};
        String[] value = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XX",
                         "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "C", "CC", "CCC", "CD",
                         "D", "DC", "DCC", "DCCC", "CM", "M", "MM", "MMM"};
        
        for (int i = 0; i < key.length; i++) {
            map.put(key[i], value[i]);
        }
        
        while (num > 0) {
            if (num / 1000 > 0) {
                sb.append(map.get((num / 1000) * 1000));
                num %= 1000;
            } else if (num / 100 > 0) {
                sb.append(map.get((num / 100) * 100));
                num %= 100;
            } else if (num / 10 > 0) {
                sb.append(map.get((num / 10) * 10));
                num %= 10;
            } else {
                sb.append(map.get(num));
                num %= 1;
            }
        }
        
        return sb.toString();
    }
}
