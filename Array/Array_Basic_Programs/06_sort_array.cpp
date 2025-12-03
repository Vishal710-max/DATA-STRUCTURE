// 06_sort_array.cpp
// This program reads an integer n and then n long long integers,
// sorts them in non-decreasing order, and prints the sorted integers. 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++)
        cout << arr[i] << (i + 1 < n ? ' ' : '\n');

    return 0;
}
