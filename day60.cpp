#include <iostream>
#include <queue>
using namespace std;

void findMedians(int N, vector<int>& branches) {
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int i = 0; i < N; i++) {
        if (maxHeap.empty() || branches[i] <= maxHeap.top())
            maxHeap.push(branches[i]);
        else
            minHeap.push(branches[i]);
        
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
        if (maxHeap.size() == minHeap.size())
            cout << (maxHeap.top() + minHeap.top()) / 2 << " ";
        else
            cout << maxHeap.top() << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> branches(N);
        for (int i = 0; i < N; i++)
            cin >> branches[i];
        findMedians(N, branches);
    }
    return 0;
}