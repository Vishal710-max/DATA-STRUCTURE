// 07_rotate_array.cpp
// Rotate an array to the right by k steps.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    long long k;
    cin >> k;

    k %= n;
    rotate(arr.begin(), arr.begin() + (n - k), arr.end());

    for (int i = 0; i < n; i++)
        cout << arr[i] << (i + 1 < n ? ' ' : '\n');

    return 0;
}
