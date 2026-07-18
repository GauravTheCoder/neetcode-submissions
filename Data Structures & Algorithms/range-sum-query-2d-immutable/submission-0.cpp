class NumMatrix {
private:
    vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        
        int rows = matrix.size();
        int cols = matrix[0].size(); // Fixed: Use matrix[0].size() for columns
        
        // Size matrix to (rows + 1) x (cols + 1) filled with 0
        prefix.assign(rows + 1, vector<int>(cols + 1, 0));
        
        // Build the prefix sum matrix correctly
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                prefix[i + 1][j + 1] = matrix[i][j] 
                                     + prefix[i][j + 1] // Fixed: Top neighbor
                                     + prefix[i + 1][j] // Fixed: Left neighbor
                                     - prefix[i][j];    // Fixed: Diagonal overlap
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        // Apply inclusion-exclusion principle in O(1)
        return prefix[row2 + 1][col2 + 1] 
             - prefix[row1][col2 + 1] 
             - prefix[row2 + 1][col1] 
             + prefix[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */