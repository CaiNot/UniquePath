#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n) {
    int ans[m][n];
    for (int i = 0; i < m; i++) {
        ans[i][0] = 1;
    }
    for (int i = 0; i < n; i++) {
        ans[0][i] = 1;
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            ans[i][j] = ans[i][j - 1] + ans[i - 1][j];
        }
    }
    return ans[m - 1][n - 1];
}

int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    int ans[n][m];
    bool flag = false;
    for (int i = 0; i < m; i++) {
        if (flag || obstacleGrid[0][i] == 1) {
            flag = true;
            ans[0][i] = 0;
        } else {
            ans[0][i] = 1;
        }
    }

    flag = false;
    for (int i = 0; i < n; i++) {
        if (flag || obstacleGrid[i][0] == 1) {
            flag = true;
            ans[i][0] = 0;
        } else {
            ans[i][0] = 1;
        }
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (obstacleGrid[i][j] == 1) {
                ans[j][i] = 0;
                continue;
            }
            ans[j][i] = ans[i][j - 1] + ans[i - 1][j];
        }
    }
    return ans[n - 1][m - 1];
}

int main() {
    std::cout << "Hello, World!" << std::endl;
//    cout << uniquePaths(7, 3);
    vector<vector<int>> input = {{0, 0},
                                 {1, 1},
                                 {0, 0}};
    cout << uniquePathsWithObstacles(input);
    return 0;
}