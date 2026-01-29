#include <bits/stdc++.h>
using namespace std;

bool safe(vector<string>& grid, int row, int col, int n) {
    for (int i = 0; i < row; i++)
 if (grid[i][col] == 'Q') 
 return false;

for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
 if (grid[i][j] == 'Q')
return false;

  for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
 if (grid[i][j] == 'Q') return false;
return true;
}

void solve(vector<vector<string>>& sol, vector<string>& grid, int row, int n) {
    if (row == n) {
        sol.push_back(grid); 
        return;
    }

for (int col = 0; col < n; col++) {
if (safe(grid, row, col, n)) {
grid[row][col] = 'Q';          
solve(sol, grid, row + 1, n);  
grid[row][col] = '.';          
        }
    }
}

vector<vector<string>> marker(int n) {
    vector<vector<string>> sol; 
    vector<string> grid(n, string(n, '.'));
    solve(sol, grid, 0, n);
    return sol;
}

int main() {
    int n = 4;
    vector<vector<string>> sol = marker(n);

    cout << "Number of solutions: " << sol.size() << endl;

    for (auto& board : sol) {
        for (auto& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}