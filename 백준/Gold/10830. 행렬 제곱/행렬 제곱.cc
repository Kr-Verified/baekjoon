#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b) {
    int n = a.size();
    vector<vector<int>> c(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int k = 0; k < n; k++) {
                sum += a[i][k] * b[k][j];
                sum %= 1000;
            }
            c[i][j] = sum;
        }
    }
    return c;
}

vector<vector<int>> ones(int n) {
    vector<vector<int>> c(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        c[i][i] = 1;
    }
    return c;
}

vector<vector<int>> pow(vector<vector<int>> a, long long int b) {
    if (b == 0) return ones(a.size());
    vector<vector<int>> half = pow(a, b / 2);
    vector<vector<int>> halfsquare = mul(half, half);

    if (b & 1) return mul(halfsquare, a);
    return halfsquare;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    long long int b = 0;
    cin >> n >> b;

    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<vector<int>> result = pow(matrix, b);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }

    return 0;
}