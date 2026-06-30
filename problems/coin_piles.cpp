#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//#include <bits/chronometer.h>
#define io_boost ios_base::sync_with_stdio(0);cin.tie(0);
using ll = long long;
using ull = unsigned long long;
const ll MOD = 1e9 + 7;
const ll MAXN = 2e5 + 7;
const ll oo = numeric_limits<ll>::max(); // 2*10^10



/* 
Time limit: 1.00 s
Memory limit: 512 MB

You have two coin piles containing a and b coins. On each move, you can either remove 
one coin from the left pile and two coins from the right pile, or two coins from the 
left pile and one coin from the right pile.
Your task is to efficiently find out if you can empty both the piles.

- Input
The first input line has an integer t: the number of tests.
After this, there are t lines, each of which has two integers a and b: the numbers of 
coins in the piles.

- Output
For each test, print "YES" if you can empty the piles and "NO" otherwise.

- Constraints
1 <= t <= 10^5
0 <= a, b <= 10^9

Example
Input:
3
2 1
2 2
3 3

Output:
YES
NO
YES
*/

/* 
@brief: We can consider the two piles of coins as just one pile of coins, and then for every move we take out  
3 coins, so in order to empty the piles in an integer number of movements, the sum of both piles most be 
divisible by 3. We can see it crearly if we construct the smallest possible pile:
1: a o b o        2: a o b o
         o             o

after that, the only way to continue having a pair of pails that could be empty by those movemnts, is by adding
coins in groups of 3, the only possible way, is by adding two in any pile and one to the other pile, and if we add
3 coins directly to one pile, it would be impossible to solve, so here it comes the last rule, with the brief. 
The smallest pile most have at leats half of the coins of the greatest pile, and the sum of them, has to be divisible by 3.
*/
int main()
{
    io_boost;

    ull t; cin >> t; 
    for (ull i = 0; i < t; ++i)
    {
        ull a, b; cin >> a; cin >> b;
        if (a > b) swap(a, b);   
        cout << ((((a + b) % 3 == 0) && (a >= b/2)) ? "YES" : "NO") << endl;  
    }
    
    return 0;
}