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
 * There are n concert tickets available, each with a certain price. Then, m customers arrive, one after another.
 * Each customer announces the maximum price they are willing to pay for a ticket, and after this, they will get a ticket with the 
 * nearest possible price such that it does not exceed the maximum price.
 * 
 * - Input
 * The first input line contains integers n and m: the number of tickets and the number of customers.
 * The next line contains n integers h_1,h_2,...,h_n: the price of each ticket.
 * The last line contains m integers t_1,t_2,...,t_m: the maximum price for each customer in the order they arrive.
 * 
 * - Output
 * Print, for each customer, the price that they will pay for their ticket. After this, the ticket cannot be purchased again.
 * If a customer cannot get any ticket, print -1.
 * 
 * - Constraints
 * 1 <= n, m <= 2.10^5
 * 1 <= h_i, t_i <= 10^9
 * 
 * Example
 * Input:
 * 5 3
 * 5 3 7 8 5
 * 4 8 3
 * 
 * Output:
 * 3
 * 8
 * -1
 */

 // 8 7 5 5 3 -1
 // 8       4 3

int main()
{
    io_boost;

    ll n, m; cin >> n; cin >> m;

    multiset<ll> prices_set;
    ll val;
    for (int i = 0; i < n; ++i)
    {
        cin >> val;
        prices_set.insert(val); // we added that price to the tree
    }

    ll desired_price = 0; 
    for (int i = 0; i < m; ++i) // for every desired_price
    {
        cin >> desired_price;

        auto it = prices_set.upper_bound(desired_price); // we search the first greater ticket for the desired_price O(log n)

        if (it == prices_set.begin()) // It means all the tickets are more expensive than the desired_price
            cout << -1 << endl; 
        else                          // We print the previous number that would be always <= than the desired_price
        {
            cout << *(--it) << endl;
            prices_set.erase(it);     // We remove that ticket withoud lossing the order to avoid purchasing it again
        }
    }     
        
    return 0;
}


// this attempt works but is so slow because is searchs decreasingly the first smaller available number  
int firstAttempt()
{
    io_boost;

    ll n, m; cin >> n; cin >> m;

    vector<ll> prices(n); 
    map<ll, ll> prices_map; // a map to count the available tickets
    
    for (int i = 0; i < n; ++i)
    {
        cin >> prices[i];
        prices_map[prices[i]] += 1; 
    }
    sort(prices.begin(), prices.end());  
    
    ll desired_price;
    bool have_found = false;
    for (int i = 0; i < m; ++i)
    {
        cin >> desired_price;

        auto it = upper_bound(prices.begin(), prices.end(), desired_price);

        if (it == prices.begin()) // It means all the tickets are more expensive 
        {
            cout << -1 << endl;
            continue;
        }

        have_found = false;
        do // we start looking for the first smaller ticket available
        {
            if (prices_map[*(--it)] != 0) // if we have ran out of tickets for that price
            {
                cout << *it << endl;
                prices_map[*it] -= 1; // we rest it from the list of reapeted numbers 
                have_found = true;
                break;
            }
        }while(it != prices.begin());

        if (!have_found)
            cout << -1 << endl;
    }

    return 0;
}