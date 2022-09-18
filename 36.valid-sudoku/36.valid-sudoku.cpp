/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    // better solution. only visit the board once
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9), cols(9), blocks(9);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue;
                char t = board[i][j];
                if (rows[i].count(t) || cols[j].count(t) 
                    || blocks[(i / 3) * 3 + j / 3].count(t)) {
                    return false;
                }
                rows[i].insert(t);
                cols[j].insert(t);
                blocks[(i / 3) * 3 + j / 3].insert(t);
            }
        }
        return true;
    }
    // my solution
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {   // check rows and cols
            unordered_set<char> row;
            unordered_set<char> col;
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.' && row.find(board[i][j]) != row.end()) {
                    return false;
                }
                row.insert(board[i][j]);
                if (board[j][i] != '.' && col.find(board[j][i]) != col.end()) {
                    return false;
                }
                col.insert(board[j][i]);
            }
        }
        for (int i = 0; i < 3; ++i) {   // check sub-box
            for (int j = 0; j < 3; ++j) {
                unordered_set<char> subBox;
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        char t = board[3 * i + k][3 * j + l];
                        if (t != '.' && subBox.find(t) != subBox.end()) {
                            return false;
                        }
                        subBox.insert(t);
                    }
                }
            }
        }
        return true;
    }
};
// @lc code=end

