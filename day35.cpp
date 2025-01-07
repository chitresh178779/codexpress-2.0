/*The villagers are preparing for a grand festival by setting up a feast by the riverside. To ensure harmony, they plan to serve dishes in perfect pairs. Each pair of dishes must have a combined taste level equal to a specific value, k. Once a pair is served, it is removed from the available dishes.

The villagers want to maximize the number of pairs they can serve. Can you help them determine the maximum number of pairs they can form?

Input Format

The first line contains an integer T, the number of test cases.
For each test case:
The first line contains two integers n (the number of dishes) and k(the required taste level for a pair).
The second line contains n integers, representing the taste levels of the dishes.
Constraints

1≤T≤100
1≤n≤10^5
1≤taste[i]≤10^9
1≤k≤10^9
Output Format

For each test case, output a single integer, representing the maximum number of pairs that can be formed. Output 0 if there is no such valid pairs.

Sample Input 0

2  
4 5  
1 2 3 4  
5 6  
3 1 3 4 3
Sample Output 0

2  
1
Explanation 0

Test Case 1: The array is [1,2,3,4] and k=5. Pair (1,4) sums to 5, remove these numbers. Pair (2,3) also sums to 5, remove these numbers. No more pairs can be formed. The total number of pairs is 2.

Test Case 2: The array is [3,1,3,4,3] and k=6. Pair (3,3) sums to 6, remove these numbers. No other pairs can sum to 6. The total number of pairs is 1.*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int maxPairs(vector<int>& dishes, int k) {
    unordered_map<int, int> freq;
    int pairs = 0;

    for (int taste : dishes) {
        freq[taste]++;
    }

    for (int taste : dishes) {
        int complement = k - taste;
        if (freq[taste] > 0 && freq[complement] > 0) {
            if (taste == complement) {
                pairs += freq[taste] / 2;
                freq[taste] = 0;
            } else {
                int count = min(freq[taste], freq[complement]);
                pairs += count;
                freq[taste] -= count;
                freq[complement] -= count;
            }
        }
    }

    return pairs;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> dishes(n);

        for (int i = 0; i < n; i++) {
            cin >> dishes[i];
        }

        cout << maxPairs(dishes, k) << endl;
    }

    return 0;
}
