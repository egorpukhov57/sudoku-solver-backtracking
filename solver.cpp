#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Returns a list of valid numbers that can be placed at matrix[y][x]
vector<int> get_candidates(const vector<vector<int>>& matrix, int x, int y) {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    // Check row and column
    for (int i = 0; i < 9; ++i) {
        // Remove matrix[y][i] if present
        auto it_row = find(arr.begin(), arr.end(), matrix[y][i]);
        if (it_row != arr.end()) {
            arr.erase(it_row);
        }
        // Remove matrix[i][x] if present
        auto it_col = find(arr.begin(), arr.end(), matrix[i][x]);
        if (it_col != arr.end()) {
            arr.erase(it_col);
        }
    }

    // Check 3x3 sub-grid
    int sr = (y / 3) * 3;
    int sc = (x / 3) * 3;
    for (int i = sr; i < sr + 3; ++i) {
        for (int j = sc; j < sc + 3; ++j) {
            auto it_grid = find(arr.begin(), arr.end(), matrix[i][j]);
            if (it_grid != arr.end()) {
                arr.erase(it_grid);
            }
        }
    }
    return arr;
}

// Solves the Sudoku puzzle using recursive backtracking
bool solve(vector<vector<int>>& matrix) {
    for (int y = 0; y < 9; ++y) {
        for (int x = 0; x < 9; ++x) {
            if (matrix[y][x] == 0) {
                vector<int> candidates = get_candidates(matrix, x, y);
                for (int num : candidates) {
                    matrix[y][x] = num;
                    if (solve(matrix)) {
                        return true;
                    }
                    matrix[y][x] = 0;  // Backtrack
                }
                return false;
            }
        }
    }
    return true;
}

int main() {
    cout << "Enter your Sudoku puzzle line by line (9 space-separated numbers, 0 for empty):" << endl;
    
    vector<vector<int>> grid(9, vector<int>(9));
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cin >> grid[i][j];
        }
    }

    cout << "\nSolving..." << endl;
    if (solve(grid)) {
        cout << "\nSolution found:" << endl;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << grid[i][j] << (j == 8 ? "" : " ");
            }
            cout << endl;
        }
    } else {
        cout << "\nNo solution exists for this puzzle." << endl;
    }

    return 0;
}
