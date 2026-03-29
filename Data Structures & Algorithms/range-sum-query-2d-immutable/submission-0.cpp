class NumMatrix {
private:
    vector<vector<int>> sums;
    int n, m;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        n = matrix.size();
        m = matrix[0].size();
        sums.resize(n);
        for (int i = 0; i < n; ++i) {
            sums[i].resize(m);
        }

        sums[n - 1][m - 1] = matrix[n - 1][m - 1];

        for (int i = n - 2; i >= 0; i--) {
            sums[i][m - 1] = matrix[i][m - 1] + sums[i + 1][m - 1];
        }
        for (int j = m - 2; j >= 0; j--) {
            sums[n - 1][j] = matrix[n - 1][j] + sums[n - 1][j + 1];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = m - 2; j >= 0; j--) {
                sums[i][j] += matrix[i][j] + sums[i + 1][j] + sums[i][j + 1] - sums[i + 1][j + 1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = 0;

        result = sums[row1][col1];
        if (row2 != n - 1 and col2 != m - 1) {
            result -= sums[row2 + 1][col1] + sums[row1][col2 + 1] - sums[row2 + 1][col2 + 1];
        }
        else {
            if (row2 != n - 1) {
                result -= sums[row2 + 1][col1];
            } 
            if (col2 != m - 1) {
                result -= sums[row1][col2 + 1];
            }
        }

        return result;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */