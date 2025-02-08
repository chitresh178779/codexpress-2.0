#include <bits/stdc++.h>
using namespace std;

void maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; 
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {

        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);
        
 
        if (i >= k - 1) {
            cout << nums[dq.front()] << " ";
        }
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T;
    cin >> T;
    while (T--) {
        int N, k;
        cin >> N >> k;
        vector<int> nums(N);
        for (int i = 0; i < N; i++) {
            cin >> nums[i];
        }
        maxSlidingWindow(nums, k);
    }
    
    return 0;
}
