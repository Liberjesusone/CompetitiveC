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
 * You are given an array of n integers, and your task is to find two values (at distinct positions) whose sum is x.
 * 
 * - Input
 * The first input line has two integers n and x: the array size and the target sum.
 * The second line has n integers a_1,a_2,...,a_n: the array values.
 * 
 * - Output
 * Print two integers: the positions of the values. If there are several solutions, you may print any of them. 
 * If there are no solutions, print IMPOSSIBLE.
 * 
 * - Constraints
 * 1 <= n <= 2.10^5
 * 1 <= x,a_i <= 10^9
 * 
 * Example
 * Input:
 * 4 8
 * 2 7 5 1
 * 
 * Output:
 * 2 4
 */


/** @brief
 * Multimap solution: insert each value with its position as we scan, and
 * immediately check if its complement (x - value) already exists in the map.
 *
 * Key insight: for each element a_i, we need a_j = x - a_i at a different position.
 * By inserting a_i BEFORE searching, we also handle the case where a_i == x - a_i
 * (same value, but different positions) — equal_range returns all copies, and we
 * filter out the one with the same index.
 *
 * Using a multimap (not map) is necessary because duplicate values can exist and
 * each one has a distinct position. O(n log n)
 */
int main()
{
    io_boost;

    ll n, x; cin >> n; cin >> x;

    multimap<ll, ll> values_map; // the value and the position

    ll value;
    for (int i = 0; i < n; ++i)
    {
        cin >> value;
        values_map.insert({value, i+1});
        
        auto range = values_map.equal_range(x-value); // we look for all the elements which summed to value = x
        for(auto it = range.first; it != range.second; ++it)
        {
            // If the position is not the same 
            if ((*it).second != i+1)
            {
                cout << i + 1 << " " << (*it).second << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}