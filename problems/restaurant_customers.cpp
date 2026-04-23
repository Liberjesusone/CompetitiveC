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
 * You are given the arrival and leaving times of n customers in a restaurant.
 * What was the maximum number of customers in the restaurant at any time?
 * 
 * - Input
 * The first input line has an integer n: the number of customers.
 * After this, there are n lines that describe the customers. Each line has two integers a and b: the arrival and 
 * leaving times of a customer.
 * You may assume that all arrival and leaving times are distinct.
 * 
 * - Output
 * Print one integer: the maximum number of customers.
 * 
 * - Constraints
 * 1 <= n <= 2.10^5
 * 1 <= a < b <= 10^9
 * 
 * Example
 * Input:
 * 3
 * 5 8
 * 2 4
 * 3 9
 * 
 * Output:
 * 2
 */

int main()
{
    io_boost;

    ll n; cin >> n;                    // amount of costumers
    vector<pair<ll, ll>> customers(n); // the pairs of first= arrival and second= leaving times
    
    // read the information of customers
    for (int i = 0; i < n; i++) {
        cin >> customers[i].first >> customers[i].second;
    }

    // just for printing the pairs to see if they were correct
    // for (int i = 0; i < n; i++)
    // {
    //     cout << customers[i].first << " - " << customers[i].second << endl;
    // }

    ll max; // max amount of costumers at a time 
    ll maxRLeaving;
    for (int i = 0; i < n; ++i)
    {   
        if (customers[i].first)
        {

        }
    }


    return 0;   
}