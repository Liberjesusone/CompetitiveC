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
 * You are given an array of n integers. You want to modify the array so that it is increasing, i.e., every element is at
 * least as large as the previous element.
 * On each move, you may increase the value of any element by one. What is the minimum number of moves required?
 * 
 * - Input
 * The first input line contains an integer n: the size of the array.
 * Then, the second line contains n integers x_1,x_2,...,x_n: the contents of the array.
 * 
 * - Output
 * Print the minimum number of moves.
 * Constraints
 * 
 * 1 <= n <= 2.10^5
 * 1 <= x_i <= 10^9
 * 
 * Example
 * Input:
 * 5
 * 3 2 5 1 7
 * 
 * Output:
 * 5
 */

int main()
{
    io_boost;


    ll n; cin >> n; 
    ll current;
    ll previous; cin >> previous;
    ll cost{0}; 
    
    for (ll i = 1; i < n; ++i)
    {
        cin >> current;
        if (previous > current)
        {
            cost += previous-current;
            continue; 
        }
        previous = current;
    }
    cout << cost << endl;

    return 0; 
}

/* 

10
50 49 48 47 46 45 44 43 42 41

*/