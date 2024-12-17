/*A robotic delivery system is operating in a straight line of houses labeled from 1 to n. The robot starts at the first house with a parcel. Every second, the robot delivers the parcel to the next house in the line. Once it reaches the last house, it changes direction and starts moving back towards the first house. For example, once the robot reaches house n, it delivers to house n - 1, then to house n - 2, and so on. Given two positive integers n (number of houses) and time (number of seconds), return the position of the house where the robot will deliver the parcel after time seconds.

Input Format

The first line contains T, the number of test cases.
Each test case consists of two positive integers n and time.
Constraints

1<=T<=1000
2<=n<=1000
1<=time<=1000
Output Format

For each test case, print the position of the house where the parcel will be delivered after time seconds.*/

#include <iostream>
using namespace std;

int findDeliveryPosition(int n, int time) {
    int cycle_length = 2 * (n - 1);
    time = time % cycle_length;
    
    if (time < n - 1) {
        return time + 1;
    } else {
        return 2 * (n - 1) - time + 1;
    }
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int n, time;
        cin >> n >> time;
        cout << findDeliveryPosition(n, time) << endl;
    }
    
    return 0;
}