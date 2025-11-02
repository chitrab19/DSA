class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
         vector<vector<int>> grid(m, vector<int>(n, 0));

        // Mark guards
        for (auto& g : guards) {
            grid[g[0]][g[1]] = 1;  // guard
        }

        // Mark walls
        for (auto& w : walls) {
            grid[w[0]][w[1]] = 2;  // wall
        }

        // Directions: up, down, left, right
        vector<vector<int>> dir = {{-1,0}, {1,0}, {0,-1}, {0,1}};

        // Mark guarded cells
        for (auto& g : guards) {
            int r = g[0], c = g[1];

            for (auto& d : dir) {
                int x = r + d[0], y = c + d[1];

                while (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] != 2 && grid[x][y] != 1) {
                    if (grid[x][y] == 0)
                        grid[x][y] = 3;  // guarded
                    x += d[0];
                    y += d[1];
                }
            }
        }

        int count = 0;
        // Count unguarded free cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) count++;
            }
        }

        return count;
    }
};