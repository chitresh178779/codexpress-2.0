/*Vansh, a hardworking farmer living in the vast deserts, spends his days harvesting dates from his palm trees. Each tree in his oasis yields a specific number of dates. Vansh keeps a detailed log of the number of dates harvested from each tree, and now he has a special task to complete. Vansh wants to know which trees yielded a specific target number of dates. Before finding these trees, he needs to sort his harvest log in non-decreasing order. Your task is to help Vansh by outputting the indices of the trees that yielded the target number of dates after sorting the log. If no tree matches the target, return an empty list. Ensure the output indices are sorted in increasing order.

Input Format

The first line will be T, the number of test cases. For each test case: The first line contains two integers N (the number of trees) and target (the target number of dates). The second line contains an array arr of size N, where arr[i] represents the number of dates harvested from the ith tree.

Constraints

1<=T<=100 1<=N<=1000 1<=target<=1000 0<= arr[i]<=1000

Output Format

For each test case, output the space-separated indices representing the trees that yielded the target number of dates after sorting the harvest log. If no tree matches the target, output an empty list.

Sample Input 0

2
3 12 
12 15 0 
10 6 
9 10 8 1 6 10 6 11 2 14
Sample Output 0

1
2 3
Explanation 0

Test Case 1

Vansh’s harvest log: [12, 15, 0]
After sorting: [0, 12, 15]
The tree that yielded 12 dates is now at index 1.
Test Case 2

Vansh’s harvest log: [9, 10, 8, 1, 6, 10, 6, 11, 2, 14]
After sorting: [1, 2, 6, 6, 8, 9, 10, 10, 11, 14]
The trees that yielded 6 dates are at indices 2 and 3.*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> findTargetIndices(const vector<int>& arr, int target) {
    vector<int> sortedArr = arr; // Copy the original array
    sort(sortedArr.begin(), sortedArr.end());

    vector<int> targetIndices;
    for (size_t i = 0; i < sortedArr.size(); ++i) { // Use size_t for the loop variable
        if (sortedArr[i] == target) {
            targetIndices.push_back(i); // 1-based index
        }
    }

    return targetIndices;
}

int main() {
    int T;
    cin >> T; // Number of test cases

    while (T--) {
        int N, target;
        cin >> N >> target; // Number of trees and target number of dates

        vector<int> arr(N);
        for (int i = 0; i < N; ++i) {
            cin >> arr[i]; // Harvest log
        }

        vector<int> result = findTargetIndices(arr, target);

        if (result.empty()) {
            cout << "" << endl; // Empty list
        } else {
            for (size_t i = 0; i < result.size(); ++i) { // Use size_t for the loop variable
                cout << result[i];
                if (i != result.size() - 1) {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }

    return 0;
}