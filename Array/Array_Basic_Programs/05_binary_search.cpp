// Binary Search Implementation in C++ 
// This program reads a sorted array and a key, then performs binary search to find the index of the key.
// If the key is found, it outputs the index; otherwise, it outputs -1. 

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    long long key;
    cin >> key;

    int left = 0, right = n - 1, ans = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == key) {
            ans = mid;
            break;
        }
        else if (arr[mid] < key) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    cout << ans;
    return 0;
}
