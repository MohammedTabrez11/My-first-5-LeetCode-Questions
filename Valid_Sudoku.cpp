// LeetCode 36. Valid Sudoku
// https://leetcode.com/problems/valid-sudoku/submissions/1595495889/

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    public:
        bool isValidSudoku(vector<vector<char>>& board) {
            // Check rows
            for(int i = 0; i < 9; i++) {
                unordered_map<char, int> hash1;
                for(int j = 0; j < 9; j++) {
                    if (board[i][j] != '.' && hash1[board[i][j]]++)  // If already exists, return false
                        return false;
                }
            }
    
            // Check columns
            for(int i = 0; i < 9; i++) {
                unordered_map<char, int> hash2;
                for(int j = 0; j < 9; j++) {
                    if (board[j][i] != '.' && hash2[board[j][i]]++)  // If already exists, return false
                        return false;
                }
            }
    
            // Check 3x3 sub-boxes
            for(int i = 0; i < 9; i += 3) {
                for(int j = 0; j < 9; j += 3) {
                    unordered_map<char, int> hash3;
                    for(int p = 0; p < 3; p++) {
                        for(int q = 0; q < 3; q++) {
                            char num = board[i + p][j + q];
                            if (num != '.' && hash3[num]++)  // If already exists, return false
                                return false;
                        }
                    }
                }
            }
            return true;
        }
    };
    