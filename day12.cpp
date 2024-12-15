/*Maria was celebrating a festival in her city . She had a large pile of sweets, and she decided to share them with her friends. However, Maria also had some playful tricks up her sleeve to make the festival more exciting.

Here’s what Maria did to keep some of the friends from getting sweets:

She engaged every k-th friend in decorating colorful lanterns.
She sent every l-th friend on a thrilling scavenger hunt across the city.
She challenged every m-th friend a puzzle to solve.
She invited every n-th friend to create intricate festival rangoli designs.
Due to these activities, all k-th, l-th, m-th, and n-th friends didn’t get any sweets.
If Maria counted a total of d friends in the city, how many friends ended up not getting any sweets?

Input Format

The first line will give T, the number of test cases.

For each test case:

The first line provides d, the total number of friends.
The second line provides k,l,m,n the activity intervals.
Constraints

1<=T<=1000
1<=k,l,m,n<=10
1<=d<=100,000
Output Format

For each test case, output the number of friends that didn’t get any sweets.

Sample Input 0

1
24
2 3 4 5
Sample Output 0

17
Explanation 0

In this case, friend 1, 7, 11, 13, 17, 19 and 23 got sweets and rest didn't.*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
using namespace std;

int main(){
int t;
cin>>t;

while(t--){
int d,k,l,m,n;
cin>>d>>k>>l>>m>>n;

set<int>occupied;

for(int i=k;i<=d;i+=k){
occupied.insert(i);
}

for(int i=l;i<=d;i+=l){
occupied.insert(i);
}

for(int i=m;i<=d;i+=m){
occupied.insert(i);
}

for(int i=n;i<=d;i+=n){
occupied.insert(i);
}

cout<<occupied.size()<<endl;
}

return 0;
}

