/*Sarthak and Samarth, while traversing a mystical desert, discover ancient scrolls hidden in mysterious pyramids. Each scroll contains a square matrix with secret symbols. To unlock the treasure hidden inside the pyramid, the scroll must satisfy two magical conditions:

All diagonal elements of the matrix must be non-zero.
All other elements of the matrix must be zero.
Your task is to design a program to determine whether the scroll unlocks the treasure based on the conditions above.

Input Format

The first line contains an integer T, the number of test cases.

For each test case:

The first line contains two integers m and n, representing the dimensions of the matrix.
The next m lines contain n integers each, representing the elements of the matrix.
Constraints

1<=T<=100
3<=m,n<=100
-100000<=matrix[i][j]<=100000
Output Format

"true" if the scroll satisfies the magical conditions to unlock the treasure.
"false" otherwise.
Sample Input 0

1 
3 3 
5 7 0 
0 3 1 
0 5 0
Sample Output 0

false
Sample Input 1

1
4 4
2 0 0 1
0 3 1 0
0 5 2 0
4 0 0 2
Sample Output 1

true*/
#include <iostream>
using namespace std;

bool isDiagonal(int matrix[100][100], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == j || i + j == m - 1) && matrix[i][j] == 0) {
                return false;
            }
            if ((i != j && i + j != m - 1) && matrix[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, n;
        cin >> m >> n;
        int matrix[100][100];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }
        if (isDiagonal(matrix, m, n)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}