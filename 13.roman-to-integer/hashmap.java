class Solution {
    public int romanToInt(String s) {
        int num = 0;
        int[] value = {1, 5, 10, 50, 100, 500, 1000};
        char[] roman = {'I', 'V', 'X', 'L', 'C', 'D', 'M'};
        Map<Character, Integer> map = new HashMap();
        
        for (int i = 0; i < value.length; i++) {
            map.put(roman[i], value[i]);
        }
        
        for (int i = 0; i < s.length(); i++) {
            num += map.get(s.charAt(i));
            if (i - 1 >= 0 && map.get(s.charAt(i - 1)) < map.get(s.charAt(i))) {
                num = num - 2 * map.get(s.charAt(i - 1));
            }
        }
        
        return num;
    }
}
