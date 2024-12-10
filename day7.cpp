// A mountain shepherd, wants to send special winter greetings to his fellow shepherds in nearby villages. However, his list of greetings is all combined into a single string using various symbols as separators, such as '.' , '@', '!' etc. Your task is to help him separate these strings into individual greetings so he can send them out clearly.

// Input Format

// The first line will be T, the number of test cases.
// Each test case will provide a single string containing greetings combined with special characters.
// Constraints

// 1≤ T≤ 500
// 1 ≤ S.size() ≤ 1000
// S contains alphanumeric characters and special symbols: {~,!,@,#,$,%,^,&,*,(,),_,+}
// Output Format

// For each test case, output the list of separated strings containing greetings.

// Sample Input 0

// 1
// warm@winter!greetings_to_you
// Sample Output 0

// warm
// winter
// greetings
// to
// you

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();
    
    set<char> delimiters = {'~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

    while (T--) {
        string S;
        getline(cin, S);
        
        vector<string> greetings;
        string currentGreeting;

        for (char c : S) {
            if (delimiters.find(c) != delimiters.end()) {
                if (!currentGreeting.empty()) {
                    greetings.push_back(currentGreeting);
                    currentGreeting.clear();
                }
            } else {
                currentGreeting += c;
            }
        }
        
        if (!currentGreeting.empty()) {
            greetings.push_back(currentGreeting);
        }
        
        for (const string& greeting : greetings) {
            cout << greeting << endl;
        }
    }
    
    return 0;
}