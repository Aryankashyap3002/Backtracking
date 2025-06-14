#include <bits/stdc++.h>
using namespace std;

int num = 0;

bool isValidBox(int i, int j, int n, vector<vector<int>> &grid) {
    return (i >= 0 && j >= 0 && i < n && j < n && grid[i][j] == 1);
}

void f(vector<vector<int>> &grid, int i, int j, int n) {
    if(i == n - 1 && j == n - 1) {
        num++;
        return;
    }

    grid[i][j] = 2; // mark as visited

    // up
    if(isValidBox(i - 1, j, n, grid)) {
        f(grid, i - 1, j, n);
    }

    // left
    if(isValidBox(i, j - 1, n, grid)) {
        f(grid, i, j - 1, n);
    }

    // down
    if(isValidBox(i + 1, j, n, grid)) {
        f(grid, i + 1, j, n);
    }

    // right
    if(isValidBox(i, j + 1, n, grid)) {
        f(grid, i, j + 1, n);
    }

    grid[i][j] = 1; // backtrack
}

int ratInAMaze(vector<vector<int>> grid, int n) {
    if(grid[0][0] == 0 || grid[n-1][n-1] == 0) return 0;
    f(grid, 0, 0, n);
    return num;
}

int main() {
    vector<vector<int>> grid = {
        {1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1}
    };

    int n = grid.size();
    cout << ratInAMaze(grid, n) << endl;
    return 0;
}
