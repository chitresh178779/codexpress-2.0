/*The adventurers are on an epic journey to conquer a series of mystical cliffs, each with its own challenge level. Each cliff has a difficulty score that determines how hard it is to scale. Your task is to help the adventurers sort these cliffs based on the "spirit energy" required to overcome them.

The "spirit energy" of a cliff is calculated as the number of 1's in its binary representation. The cliffs should be sorted in ascending order of their spirit energy. If two or more cliffs have the same spirit energy, sort them by their difficulty scores in ascending order.

Input Format

The first line will contain T, the number of test cases. For each test case:

The first line contains N, the number of cliffs.
The second line contains N space-separated integers, where each integer represents the difficulty score of a cliff.
Constraints

1≤T≤100
1≤N≤1000
0≤difficulty score≤1,000,000
Output Format

For each test case, output the sorted list of cliff difficulty scores.

Sample Input 0

1
7
5 3 2 5 8 2 7
Sample Output 0

2 2 8 3 5 5 7*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> precomputeSpiritEnergy(int maxDifficulty) {
    vector<int> spiritEnergy(maxDifficulty + 1);
    for (int i = 0; i <= maxDifficulty; ++i) {
        spiritEnergy[i] = __builtin_popcount(i);
    }
    return spiritEnergy;
}

void solve(vector<int>& spiritEnergy) {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> cliffs(N);
        int maxCliff = 0;
        for (int i = 0; i < N; ++i) {
            cin >> cliffs[i];
            maxCliff = max(maxCliff, cliffs[i]);
        }

        if (maxCliff >= (int)spiritEnergy.size()) {
            int currentSize = spiritEnergy.size();
            spiritEnergy.resize(maxCliff + 1);
            for (int i = currentSize; i <= maxCliff; ++i) {
                spiritEnergy[i] = __builtin_popcount(i);
            }
        }

        stable_sort(cliffs.begin(), cliffs.end(), [&](int a, int b) {
            if (spiritEnergy[a] != spiritEnergy[b]) {
                return spiritEnergy[a] < spiritEnergy[b];
            }
            return a < b;
        });

        for (int i = 0; i < N; ++i) {
            cout << cliffs[i] << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int INITIAL_MAX_DIFFICULTY = 1000000;
    
    vector<int> spiritEnergy = precomputeSpiritEnergy(INITIAL_MAX_DIFFICULTY);

    solve(spiritEnergy);

    return 0;
}