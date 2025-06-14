class Solution {
public:
    // Recursive function to check if a path from (i,j) to (m-1,n-1) is valid
    // given the current health value
    bool canSurviveWithHealth(vector<vector<int>>& dungeon, int rows, int cols, int i, int j, int health) {
        // Out of bounds
        if (i >= rows || j >= cols)
            return false;

        // Reduce health by current cell's value
        health += dungeon[i][j];

        // If health drops below 1, path is invalid
        if (health < 1)
            return false;

        // If destination is reached, check if health is still positive
        if (i == rows - 1 && j == cols - 1)
            return true;

        // Try moving down or right
        bool moveDown = canSurviveWithHealth(dungeon, rows, cols, i + 1, j, health);
        bool moveRight = canSurviveWithHealth(dungeon, rows, cols, i, j + 1, health);

        return moveDown || moveRight;
    }

    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon[0].size();

        int low = 1, high = 1e9;  // health range (minimum is 1)
        int answer = -1;

        // Binary search to find the minimum health needed
        while (low <= high) {
            int mid = (low + high) / 2;

            // Check if we can survive the dungeon starting with `mid` health
            if (canSurviveWithHealth(dungeon, rows, cols, 0, 0, mid)) {
                answer = mid;       // This might be the answer
                high = mid - 1;     // Try to find a smaller valid health
            } else {
                low = mid + 1;      // Increase the health if current one is not enough
            }
        }

        return answer;
    }
};
