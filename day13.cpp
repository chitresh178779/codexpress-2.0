/*The IPL (Indian Premier League) auction is in full swing, and team owners are competing to complete their squads. Each player in the auction has a unique jersey number representing them. The goal is to pick k new players whose jersey numbers are not already in the team's current lineup. The cost of bidding for a player is equal to their jersey number.

The team owner wants to ensure that they recruit k new players at the minimum possible cost. You are tasked with helping the team owner determine the minimum bidding cost required to add k new players to their squad.

Input Format

The first line will contain T, the number of test cases.

For each test case:

The first line will contain n, the number of players already in the team, and k (the number of players to recruit).
The second line will contain an array team_lineup of n integers, representing the jersey numbers of players already in the team.
Constraints

1<=T<=10^3
1<=K<=10^8
1<=n<=10^5
1<=team_lineup[i]<=10^9
Output Format

For each test case, output the minimum bidding cost required to add k new players to the team.*/


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        long long n, k;
        cin >> n >> k;

        vector<long long> team_lineup(n);
        for (long long i = 0; i < n; ++i) {
            cin >> team_lineup[i];
        }

        sort(team_lineup.begin(), team_lineup.end());
        team_lineup.erase(unique(team_lineup.begin(), team_lineup.end()), team_lineup.end());

        long long cost = 0, next_missing = 1;

        for (long long jersey : team_lineup) {
            while (next_missing < jersey && k > 0) {
                cost += next_missing;
                next_missing++;
                k--;
            }
            next_missing = jersey + 1;
        }

        while (k > 0) {
            cost += next_missing;
            next_missing++;
            k--;
        }

        cout << cost << "\n";
    }

    return 0;
}