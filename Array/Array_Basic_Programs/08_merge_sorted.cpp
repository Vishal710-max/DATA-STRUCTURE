// Merge Two Sorted Arrays
// Given two sorted arrays A and B, merge them into a single sorted array C.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<long long> A(n), B(m);
    for (int i = 0; i < n; i++) cin >> A[i];
    for (int j = 0; j < m; j++) cin >> B[j];

    vector<long long> C;
    C.reserve(n + m);

    int i = 0, j = 0;
    while (i < n && j < m) {
        if (A[i] <= B[j]) C.push_back(A[i++]);
        else C.push_back(B[j++]);
    }
    while (i < n) C.push_back(A[i++]);
    while (j < m) C.push_back(B[j++]);

    for (int t = 0; t < C.size(); t++)
        cout << C[t] << (t + 1 < C.size() ? ' ' : '\n');

    return 0;
}
