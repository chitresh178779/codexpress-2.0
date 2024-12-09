// Naman and Mohit are playing a mystical Stone Reversal Game. They take turns handing each other a name engraved on a magical stone. The challenge is to reverse the name on the stone up to a specific position and read aloud the new magical word. Write a program to help Naman and Mohit perform this magical transformation.

// Input Format

// Take T test cases as the input.
// First line of input under each test case should be K, the position up to which the magical name has to be reversed.
// Second line of input should be the magical name S engraved on the stone
// Constraints

// 1≤ T≤ 1000
// 1 ≤ S.size() ≤ 1000
// 0≤ K ≤S.size()
// Output Format

// Print the newly reversed magical name for each test case.
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int T;
    cin>>T;
    while(T--){
        int K;
        cin>>K;
        string s;
        cin>>s;
        reverse(s.begin(),s.begin()+K);
        cout<<s<<endl;
    }
    return 0;
}
