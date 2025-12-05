// 10_frequency_count.cpp
// Given a list of integers, count the frequency of each unique integer
// and print them in ascending order of the integers. 

#include <iostream>
#include <map>
using namespace std;

int main() {
    int n;
    cin >> n;

    map<long long, int> freq;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        freq[x]++;
    }

    bool first = true;
    for (auto &p : freq) {
        if (!first) cout << " ";
        cout << p.first << ":" << p.second;
        first = false;
    }

    return 0;
}
