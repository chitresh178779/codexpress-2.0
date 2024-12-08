#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int findBalancedTent(const vector<int>& L) {
    int totalSum = 0, leftSum = 0;
    for (int num : L) totalSum += num;

    for (int i = 0; i < L.size(); i++) {
        totalSum -= L[i];
        if (leftSum == totalSum) return i;
        leftSum += L[i];
    }
    return -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<int> L(N);
        for (int i = 0; i < N; i++) {
            cin >> L[i];
        }

        cout << findBalancedTent(L) << endl;
    }

    return 0;
}