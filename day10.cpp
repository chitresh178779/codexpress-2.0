/*As Tenzing prepared for his historic journey to conquer Mount Everest, he meticulously maintained a diary to keep track of important milestones during his climb. Each day of the year marked a significant step in his preparation, and during the expedition, dates helped him recall key events like when they set up camps or when they reached specific altitudes.

You are given a date in the format DDMMM, and your task is to calculate the day of the year that the given date falls on. Assume that the year is a non-leap year. Help Tenzing record the exact day count from the beginning of the year to organize his Everest journey effectively.

Input Format

The first line will provide T, the number of test cases.
Each test case will provide a date in the format DDMMM.
Constraints

1≤ T≤ 500
Output Format

For each test case, output the day count of the given date from the start of the year.*/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int main() {
    unordered_map<string, int> monthDays = {
        {"JAN", 0}, {"FEB", 31}, {"MAR", 59}, {"APR", 90}, 
        {"MAY", 120}, {"JUN", 151}, {"JUL", 181}, {"AUG", 212}, 
        {"SEP", 243}, {"OCT", 273}, {"NOV", 304}, {"DEC", 334}
    };
    
    int T;
    cin >> T;
    
    while (T--) {
        string date;
        cin >> date;
        int day = stoi(date.substr(0, 2));
        string month = date.substr(2, 3);
        int dayOfYear = monthDays[month] + day;
        cout << dayOfYear << endl;
    }
    
    return 0;
}