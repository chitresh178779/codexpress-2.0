/*In the vast stretches of the desert, life is a constant struggle against the elements. Mranal, a desert dweller, relies on careful resource management to survive. Each day, he collects supplies like water containers, food bags, and other essentials, each represented by a weight in kilograms. To keep his camel caravan balanced, he needs to pair supplies such that the total weight of each pair equals exactly k. Mranal’s goal is to form the maximum number of such pairs to ensure that the journey through the arid sands is efficient and nothing is wasted. Can you help Mranal optimize his pairings and survive another day in the desert?

Input Format

The input format remains unchanged:
The first line will be T, the number of test cases.
For each test case:
The first line gives n, the number of supplies, and k, the target weight for each pair.
The second line contains an array masses of n integers, representing the weights of the supplies.
Constraints

1<=T<=10^3
1<=K<=10^8
1<=n<=10^3
0<=masses[i]<=10^9
Output Format

For each test case, output the maximum number of pairs Mranal can form.

Sample Input 0

1  
4 5  
1 2 3 4
Sample Output 0

2
Explanation 0

Starting with masses = [1, 2, 3, 4]:

Remove weights 1 and 4, then masses = [2, 3].
Remove weights 2 and 3, then masses = [].
There are no more pairs that sum up to 5, hence a total of 2 operations.*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        vector<int> masses(n);
        for (int i = 0; i < n; i++) {
            cin >> masses[i];
        }

        unordered_map<int, int> freq;
        int maxPairs = 0;

        for (int weight : masses) {
            int complement = k - weight;

            if (freq[complement] > 0) {
                maxPairs++;
                freq[complement]--;
            } else {
                freq[weight]++;
            }
        }

        cout << maxPairs << endl;
    }

    return 0;
}