class Solution {
public:
    // Recursive function to calculate the minimum health required to reach (m-1, n-1) from (i, j)
    int getMinHealth(vector<vector<int>>& dungeon, int i, int j, int m, int n) {
        // If out of bounds, return INT_MAX as this path is invalid
        if (i >= m || j >= n)
            return INT_MAX;

        // If we're at the destination cell (bottom-right)
        if (i == m - 1 && j == n - 1) {
            // If the dungeon value is negative, we need more health to survive
            if (dungeon[i][j] < 0)
                return abs(dungeon[i][j]) + 1;
            else
                // Otherwise, we just need 1 health to survive
                return 1;
        }

        // Recursive calls to right and down cells
        int minHealthRight = getMinHealth(dungeon, i, j + 1, m, n);
        int minHealthDown = getMinHealth(dungeon, i + 1, j, m, n);

        // Take the smaller of the two health requirements
        int minHealthNext = min(minHealthRight, minHealthDown);

        // If current cell contributes positively or is not too negative,
        // reduce the health needed from the next cell
        if (dungeon[i][j] < minHealthNext) {
            return minHealthNext - dungeon[i][j];
        } else {
            // At minimum, we always need 1 health to stay alive
            return 1;
        }
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        return getMinHealth(dungeon, 0, 0, m, n);
    }
};
