class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& grid) {
        
        int m = grid.size();    // Number of rows
        int n = grid[0].size(); // Number of columns
        
        // Create a 2D DP table where dp[i][j] stores the minimum health needed at cell (i, j)
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Iterate from bottom-right to top-left
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                // Base case: last cell (bottom-right)
                if (i == m - 1 && j == n - 1) {
                    if (grid[i][j] >= 0)
                        dp[i][j] = 1; // Minimum 1 health is needed to survive
                    else
                        dp[i][j] = abs(grid[i][j]) + 1; // Need more health if cell is harmful
                }
                else {
                    // Get health needed from right and down cells (if in bounds), else use INT_MAX
                    int right = (j + 1 < n) ? dp[i][j + 1] : INT_MAX;
                    int down = (i + 1 < m) ? dp[i + 1][j] : INT_MAX;

                    // Find the minimum health needed from the two paths
                    int minNextHealth = min(right, down);

                    // If current cell value is less than required, calculate extra needed
                    if (minNextHealth > grid[i][j])
                        dp[i][j] = minNextHealth - grid[i][j];
                    else
                        dp[i][j] = 1; // Minimum 1 health is always required
                }
            }
        }

        // Return minimum health needed at the start (top-left)
        return dp[0][0];
    }
};
