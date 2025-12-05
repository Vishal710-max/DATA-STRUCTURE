// 09_remove_duplicates.cpp
// Given a sorted array, remove the duplicates in place such that each element appears only once
// and return the new length. Do not allocate extra space for another array; you must do this by
// modifying the input array in place with O(1) extra memory.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 0) return 0;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int idx = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1])
            arr[idx++] = arr[i];
    }

    for (int i = 0; i < idx; i++)
        cout << arr[i] << (i + 1 < idx ? ' ' : '\n');

    return 0;
}
