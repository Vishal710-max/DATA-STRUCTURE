// 03_max_min.cpp
// Find the maximum and minimum elements in an array of integers.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    long long mx = *max_element(arr.begin(), arr.end());
    long long mn = *min_element(arr.begin(), arr.end());

    cout << "Max: " << mx << " Min: " << mn;
    return 0;
}
