class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) return s;
        
        StringBuilder[] ss = new StringBuilder[numRows];
        for (int i = 0; i < numRows; i++) {
            ss[i] = new StringBuilder();
        }
        
        boolean down = true;
        int row = 0;
        for (char c : s.toCharArray()) {
            ss[row].append(c);
            if (down) row++;
            else row--;
            
            if (row == numRows - 1 || row == 0) {
                down = !down;    
            }
        }
        
        StringBuilder ret = new StringBuilder();
        for (StringBuilder sb : ss) ret.append(sb.toString());
        
        return ret.toString();
    }
}
