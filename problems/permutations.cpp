#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define io_boost ios_base::sync_with_stdio(0);cin.tie(0);
using ll = long long;
using ull = unsigned long long;
const ll MOD = 1e9 + 7;
const ll MAXN = 2e5 + 7;
const ll oo = numeric_limits<ll>::max();

/** @brief
 * Time limit: 1.00 s
 * Memory limit: 512 MB
 * 
 * A permutation of integers 1,2,...,n is called beautiful if there are no adjacent elements whose difference is 1.
 * Given n, construct a beautiful permutation if such a permutation exists.
 * 
 * - Input
 * The only input line contains an integer n.
 * 
 * - Output
 * Print a beautiful permutation of integers 1,2,...,n. If there are several solutions, you may print any of them. 
 * If there are no solutions, print "NO SOLUTION".
 * 
 * Constraints
 * 1 <= n <= 10^6
 * 
 * Example 1
 * Input:
 * 5
 * 
 * Output:
 * 4 2 5 3 1
 * 
 * Example 2
 * Input:
 * 3
 * 
 * Output:
 * NO SOLUTION
 */

int main()
{
    io_boost;

    ll n; cin >> n;
    
    if (n == 2 || n == 3)
    {
        cout << "NO SOLUTION" << endl;
        return 0;
    }
    for (ll i = 1; i <= n/2; ++i) // print even numbers
        cout << i*2 << " ";
    for (ll i = 0; i < ceil(n/2.0); ++i) // print odd numbers
        cout << i*2 + 1 << " ";
    cout << endl;

    return 0;
}

/*

1: 1
2: 1 2     -X
3: 2 1 3   -X
4: 2 4 1 3 
5: 2 4 1 3 5
6: 2 4 6 1 3 5
7: 2 4 6 1 3 5 7
8: 2 4 6 8 1 3 5 7 
9: 2 4 6 8 1 3 5 7 9
10: 2 4 6 8 10 1 3 5 7 9
11: 2 4 6 8 10 1 3 5 7 9 11
*/