#include<iostream>
using namespace std;
int main(){
    return 0;
}/*Reena and Meena are adventurous rock climbers who love to climb rocky mountains. They start from a specific position on the mountain wall and follow a series of climbing instructions. Reena begins at a point (𝑥,𝑦) on the mountain wall. The instructions are provided in the form of a string s. The string contains the following symbols that dictate the movement:

U - Upwards (North direction)
D - Downwards (South direction)
R - Rightwards (East direction)
L - Leftwards (West direction)
The integers followed by the above symbols in the string signify the distance (in meters) that Reena and Meena must climb in the respective direction (U, D, R, L).

Your task is to calculate the Euclidean distance from their starting point on the ground (0,0) to their final position on the mountain wall after following the entire set of climbing instructions.

Input Format

The first line contains T, the number of test cases (1≤T≤1000). For each test case:

The first line contains two integers x and y(−100,000≤x,y≤100,000) which denote the initial position of Reena and Meena on the mountain wall.
The second line for each test case contains a string s(1≤∣s∣≤1000), representing the climbing instructions.
The string s contains uppercase letters (U, D, R, L) and digits. The letters specify the direction, and the digits specify the distance to climb in that direction.
Constraints

1≤T≤1000 (Number of test cases)
−100,000≤x,y≤100,000 (Initial coordinates)
1≤∣s∣≤1000 (Length of instruction string)
s only contains uppercase letters U, D, R, L and digits.
Output Format

For each test case, print the Euclidean distance from the origin (0,0) to the final position on the wall, rounded to 2 decimal places.

Sample Input 0

1  
3 4  
U2R3D6  
Sample Output 0

6.00*/

#include <iostream>
#include <cmath>
#include <string>
#include <iomanip>
using namespace std;

double calculate_distance(int x, int y, const string& instructions) {
    int n = instructions.length();
    int i = 0;

    while (i < n) {
        char direction = instructions[i];
        int distance = 0;
        i++;
        while (i < n && isdigit(instructions[i])) {
            distance = distance * 10 + (instructions[i] - '0');
            i++;
        }
        if (direction == 'U') {
            y += distance;
        } else if (direction == 'D') {
            y -= distance;
        } else if (direction == 'R') {
            x += distance;
        } else if (direction == 'L') {
            x -= distance;
        }
    }

    return sqrt(1.0 * x * x + 1.0 * y * y);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int x, y;
        string instructions;
        cin >> x >> y >> instructions;
        cout << fixed << setprecision(2) << calculate_distance(x, y, instructions) << '\n';
    }

    return 0;
}
