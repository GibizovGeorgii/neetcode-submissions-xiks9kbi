class NumMatrix {
public:

//full matrix
//prefix sum 1d
//prefix sum 2d


	std::vector<std::vector<int>> sums;

	NumMatrix(std::vector<std::vector<int>>& matrix)
	{
		int nr = (int)matrix.size();
		int nc = (int)matrix[0].size();
		sums = std::vector<std::vector<int>>(nr + 1, std::vector<int>(nc + 1, 0));

		for (int r = 1; r <= nr; ++r)
		{
			for (int c = 1; c <= nc; ++c)
			{
				sums[r][c] = matrix[r - 1][c - 1] +
							sums[r - 1][c] +
							sums[r][c - 1] -
							sums[r - 1][c - 1];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2)
	{
		return sums[row2 + 1][col2 + 1] -
				sums[row1][col2 + 1] -
				sums[row2 + 1][col1] +
				sums[row1][col1];
	}
};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */