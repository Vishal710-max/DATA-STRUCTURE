// Linear Search in C++ 
// This program reads an integer n, followed by n integers into an array,
// and then reads a key to search for in the array. 
// It performs a linear search to find the index of the key in the array. 

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

    int index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            index = i;
            break;
        }
    }

    cout << index;
    return 0;
}
