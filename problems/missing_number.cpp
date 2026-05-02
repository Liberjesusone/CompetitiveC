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
 * You are given all numbers between 1,2,...,n except one. Your task is to find the missing number.
 * 
 * - Input
 * The first input line contains an integer n.
 * The second line contains n-1 numbers. Each number is distinct and between 1 and n (inclusive).
 * 
 * - Output
 * Print the missing number.
 * 
 * - Constraints
 * 2 <= n <= 2.10^5
 * 
 * Example
 * Input:
 * 5
 * 2 3 1 5
 * 
 * Output:
 * 4
 */

int main()
{
    io_boost;

    ll n; cin >> n;

    ll num;
    ll sum = 0;
    for (ll i = 0; i < n-1; ++i)
    {
        cin >> num;
        sum += num;
    }
    // summing of all natural number  n(n+1)/2
    cout << (n*(n+1) / 2 ) -sum << endl;

    return 0;
}

int main2()
{
    io_boost;
    ll n; cin >> n;

    set<ll> all_numbers_from_1_to_n; 
    for (int i = 1; i <= n; ++i)
        all_numbers_from_1_to_n.insert(i);

    ll num;
    for (ll i = 0; i < n-1; ++i)
    {
        cin >> num; 
        all_numbers_from_1_to_n.erase(num);        
    }
    cout << *all_numbers_from_1_to_n.begin() << endl;
    
    return 0;
}