/*In the midst of exploring a vast desert, archaeologists have discovered a unique set of sandstone formations, each with a distinct rarity value. To preserve these formations, they want to create a collection of k distinct sandstones. The thrill of a collection is determined by the smallest absolute difference in rarity values between any two selected sandstones. You are given an array of integer rarity values where rarity[i] denotes the rarity of the ith sandstone and an integer k, which represents the number of distinct sandstones in the collection. The best match value of a sandstone collection is the smallest absolute difference of the rarity values of any two sandstones in the collection. In the Desert Sandstone Rarity Challenge, the goal is to find the maximum best match value of a sandstone collection by selecting k distinct sandstones.

Input Format

The first line will be T, the number of test cases.
The first line of each test case will give N, the size of the array, and a positive integer k, the number of distinct sandstones in the collection.
The second line of each test case will give array rarity where rarity[i] denotes the rarity of the ith sandstone.
Constraints

1<=T<=100
1<=N<=1000
1<=k<=N
1<=rarity[i]<=1,00,000
Output Format

For each test case, output the maximum best match value of a sandstone collection.

Sample Input 0

1
3 2
1 3 1
Sample Output 0

2
Explanation 0

Choose the sandstones with rarity values [1,3]. The best match value of this package is calculated as the smallest difference between their rarity values: min(∣1−3∣)=min(2)=2. It can be proven that 2 is the maximum enjoyment value that can be achieved.

Sample Input 1

1  
6 3  
13 5 1 8 21 2  
Sample Output 1

8*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPickWithDifference(const vector<int>& rarity, int k, int mid) {
    int count = 1;
    int lastPicked = rarity[0];

    for (int i = 1; i < rarity.size(); i++) {
        if (rarity[i] - lastPicked >= mid) {
            count++;
            lastPicked = rarity[i];
        }
        if (count >= k) {
            return true;
        }
    }
    return false;
}

int findMaxBestMatch(const vector<int>& rarity, int k) {
    int low = 0, high = rarity.back() - rarity[0];
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (canPickWithDifference(rarity, k, mid)) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, k;
        cin >> N >> k;
        vector<int> rarity(N);
        for (int i = 0; i < N; i++) {
            cin >> rarity[i];
        }
        sort(rarity.begin(), rarity.end());
        cout << findMaxBestMatch(rarity, k) << endl;
    }
    return 0;
}