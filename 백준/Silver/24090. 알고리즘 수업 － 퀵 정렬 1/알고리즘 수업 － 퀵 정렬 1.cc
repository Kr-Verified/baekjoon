#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>

using namespace std;

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &A, int start, int end, int& cnt, int &k) {
    int x = A[end];
    int i = start-1;
    for (int j = start; j < end; j++) {
        if (A[j] <= x) {
            if (++cnt == k) {
                cout << min(A[i+1], A[j]) << " " << max(A[i+1], A[j]);
                exit(0);
            }
            swap(A[++i], A[j]);
        }
    }
    if (i+1 != end) {
        if (++cnt == k) {
            cout << min(A[i+1], A[end]) << " " << max(A[i+1], A[end]);
            exit(0);
        }
        swap(A[i+1], A[end]);
    }

    return i+1;
}

void quick_sort(vector<int> &A, int start, int end, int& cnt, int &k) {
    if (start < end) {
        int q = partition(A, start, end, cnt, k);
        quick_sort(A, start, q-1, cnt, k);
        quick_sort(A, q+1, end, cnt, k);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, k, cnt=0;
    cin >> n >> k;
    vector<int> A(n);
    for (int i = 0; i < n; i++) cin >> A[i];
    quick_sort(A, 0, n-1, cnt, k);
    cout << -1 << '\n';
    return 0;
}