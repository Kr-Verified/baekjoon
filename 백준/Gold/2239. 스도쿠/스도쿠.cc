#include <iostream>
#include <vector>
using namespace std;

bool back(vector<vector<int>>& field,
          vector<int>& box_used,
          vector<int>& row_used,
          vector<int>& col_used,
          int x, int y) {
    if (field[y][x] != 0) {
        int nx = x + 1, ny = y;
        if (nx == 9) { nx = 0; ny++; }
        if (ny == 9) return true;
        return back(field, box_used, row_used, col_used, nx, ny);
    }

    int box_idx = (y / 3) * 3 + (x / 3);

    for (int num = 1; num <= 9; num++) {
        int mask = 1 << num;
        if (row_used[y] & mask) continue;
        if (col_used[x] & mask) continue;
        if (box_used[box_idx] & mask) continue;

        field[y][x] = num;
        row_used[y] |= mask;
        col_used[x] |= mask;
        box_used[box_idx] |= mask;

        int nx = x + 1, ny = y;
        if (nx == 9) { nx = 0; ny++; }

        if (ny == 9 || back(field, box_used, row_used, col_used, nx, ny))
            return true;

        field[y][x] = 0;
        row_used[y] &= ~mask;
        col_used[x] &= ~mask;
        box_used[box_idx] &= ~mask;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<vector<int>> field(9, vector<int>(9));
    vector<int> row_used(9, 0);
    vector<int> col_used(9, 0);
    vector<int> box_used(9, 0);

    for (int i = 0; i < 9; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < 9; j++) {
            field[i][j] = s[j] - '0';
            if (field[i][j] != 0) {
                int mask = 1 << field[i][j];
                row_used[i] |= mask;
                col_used[j] |= mask;
                box_used[(i / 3) * 3 + (j / 3)] |= mask;
            }
        }
    }

    back(field, box_used, row_used, col_used, 0, 0);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++)
            cout << field[i][j];
        cout << '\n';
    }

    return 0;
}
