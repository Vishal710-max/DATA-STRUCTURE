// 02_reverse_array.cpp
// This program reads an integer n followed by n integers,
// reverses the order of the integers, and outputs them.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    for (int i = n - 1; i >= 0; i--) {
        cout << arr[i] << (i ? ' ' : '\n');
    }
    return 0;
}
