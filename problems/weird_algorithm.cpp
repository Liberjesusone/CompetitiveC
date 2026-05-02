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
 * Consider an algorithm that takes as input a positive integer n. If n is even, the algorithm divides it by two, and if n is odd, 
 * the algorithm multiplies it by three and adds one. The algorithm repeats this, until n is one. For example, the sequence for n=3 
 * is as follows:
 * 
 * 3 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
 * 
 * Your task is to simulate the execution of the algorithm for a given value of n.
 * 
 * - Input
 * The only input line contains an integer n.
 * 
 * - Output
 * Print a line that contains all values of n during the algorithm.
 * 
 * Constraints
 * 
 * 1 <= n <= 10^6
 * 
 * Example
 * Input:
 * 3
 * 
 * Output:
 * 3 10 5 16 8 4 2 1
 */


int main()
{
    io_boost;

    ll n; cin >> n;
    cout << n << " ";
    while (n != 1)
    {
        if (n % 2 == 0)
            n /= 2;
        else 
            n = n * 3 + 1;
        cout << n << " ";
    }
    cout << endl;
    
    return 0;
}