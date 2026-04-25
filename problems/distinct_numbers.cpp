#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define io_boost ios_base::sync_with_stdio(0);cin.tie(0);
using ll = long long;
using ull = unsigned long long;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll MAXN = 2e5 + 7;
ll n, m, q;
const ll oo = numeric_limits<ll>::max();

/** @brief
 * Time limit: 1.00 s
 * Memory limit: 512 MB
 * 
 * You are given a list of n integers, and your task is to calculate the number of distinct values in the list.
 * 
 * - Input
 * The first input line has an integer n: the number of values.
 * The second line has n integers x_1,x_2,...,x_n.
 * 
 * - Output
 * Print one integers: the number of distinct values.
 * Constraints
 * 
 * 1 <= n <= 2.10^5
 * 1 <= x_i <= 10^9
 * 
 * Example
 * Input:
 * 5
 * 2 3 2 2 3
 * 
 * Output:
 * 2
 */


// To solve this problem we only have to use a map to store the numbers, because it's a O(1) complextity to add a number, 
// and as we are adding them we will only have one record for every number, with a short = 1 representing that we have found 
// that number in the list, and the we will return the amount of distintc numbers founds, as the size of that map. acording 
// to the map data structure that only has one record for every key 
int main()
{
    io_boost;

    ll n; cin >> n;
    map<ll, short> numbers;
    
    ll val;
    for (int i = 0; i < n; ++i)
    {
        cin >> val;
        numbers[val] = 1;
    }

    cout << numbers.size() << endl;

    return 0;
}