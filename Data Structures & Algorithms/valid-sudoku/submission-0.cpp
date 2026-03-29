class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;

        std::vector<std::vector<int>> rows (9, std::vector<int> (n, 0));
        std::vector<std::vector<int>> cols (9, std::vector<int> (n, 0));
        std::vector<std::vector<int>> boxes (9, std::vector<int> (n, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int number = board[i][j] - '0';

                int box_index = (i / 3) * 3 + j / 3;
                if (rows[i][number - 1] == 1 or cols[j][number - 1] == 1 or boxes[box_index][number - 1] == 1) {
                    return false;
                } else {
                    rows[i][number - 1]++; 
                    cols[j][number - 1]++;
                    boxes[box_index][number - 1]++;
                }
            }
        }
        return true;
    }
};
