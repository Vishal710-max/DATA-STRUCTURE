// 01_sum_of_array.cpp
// This program reads an integer n followed by n integers,
// computes their sum, and outputs the result.

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    cout << sum;
    return 0;
}
