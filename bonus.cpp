#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        string participants;
        cin >> participants;
        
        int females = 0, males = 0;
        
        // Count number of females and males
        for (char c : participants) {
            if (c == 'F') females++;
            else males++;
        }
        
        // The maximum number of valid teams is the minimum of:
        // - the number of females (since each team needs at least one female)
        // - the total number of complete teams that can be formed (n / 4)
        int max_teams = min(females, n / 4);
        
        cout << max_teams << endl;
    }
    
    return 0;
}