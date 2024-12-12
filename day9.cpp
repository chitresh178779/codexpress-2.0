// In a quaint hilly village, artisans weave beautiful tapestries containing palindromic patterns of lowercase English letters. The village elder has requested to modify exactly one character in each tapestry to ensure the pattern is no longer palindromic, while still maintaining its beauty. Moreover, the modified pattern should be the lexicographically smallest one possible. If it’s impossible to achieve this for a given tapestry, output -1.

// Help the artisans by writing a program that determines the modified pattern or returns -1 if the modification cannot be achieved.

// Input Format

// The first line will be T, the number of testcases.
// Each testcase will provide a palindromic string representing a tapestry pattern that needs modification.
// Constraints

// 1≤ T≤ 1000
// 1≤ palindrome.length≤ 1000
// Palindromic string consists of only lowercase English letters.
// Output Format

// For each testcase, output the lexicographically smallest resulting (non-palindromic) string after the modification. If it is not possible, output -1.



#include <iostream>
#include <string>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        long int n = s.length();

        if (n == 1) {
            cout << -1 << endl;
            continue;
        }

        bool modified = false;

        for (int i = 0; i < n / 2; ++i) {
            if (s[i] != 'a') {
                s[i] = 'a';
                modified = true;
                break;
            }
        }

        if (!modified) {
            s[n - 1] = 'b';
        }

        cout << s << endl;
    }

    return 0;
}
