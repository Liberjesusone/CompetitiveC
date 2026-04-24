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


/** @brief
 * this function has a O(n.log(n)) to do the sorting part, and then it has a O(n) loop to recreate the restaurant day and we only use a
 * an array of O(2n) so it is O(n) in space
 * 
 * Its made based on the Event Sorting tecnic, basically putting all the events in order as they happenend, and then recreate the escene
 * updating the current stats on every part 
 */
int main()
{
    io_boost;

    ll n; cin >> n; 
    vector<pair<ll, int>> customers(n);

    for (int i = 0; i < n; ++i)
    {
        pair<ll, int> arrival = {0, 1}; // arrival time - 1
        pair<ll, int> leaving = {0, -1}; // leaving time - -1
        
        cin >> arrival.first >> leaving.first;

        customers.push_back(arrival); // here we add the pairs
        customers.push_back(leaving);
    }

    // the we sort the customers by its first ll, so we have all the events in arrival order, and we can recreate the restaurant day 
    sort(customers.begin(), customers.end(), [](pair<ll, int> a, pair<ll, int> b) {
        return a.first < b.first;
    });

    ll best = 0;
    ll current_sum = 0; 
    for (auto pair : customers)
    {   
        current_sum += pair.second;     // if this event is a customer arriving it will be +1 otherwise -1
        best = max(best, current_sum);  // we update the best amount of customers
    }

    cout << best << endl;

    return 0;
}

int FirstAttempt()
{
    io_boost;

    ll n; cin >> n;                    // amount of costumers
    vector<pair<ll, ll>> customers(n); // the pairs of first= arrival and second= leaving times
    vector<ll> all_hours(2*n);

    auto has_this_hour = [](pair<ll, ll> pair, ll hour)
    {
        if (pair.first <= hour && hour <= pair.second)
            return true;
        else return false;
    };

    // read the information of customers
    for (int i = 0; i < n; i++) 
    {
        cin >> customers[i].first >> customers[i].second;

        all_hours[2*i] = customers[i].first;      // We save the numbers being ingresed 
        all_hours[2*i + 1] = customers[i].second;
    }

    ll best_max = 0; // max amount of costumers at a time 

    for (int i = 0; i < 2*n; ++i) // We iterate each hour 
    {   
        ll customers_per_hour = 0;
        ll hour = all_hours[i];
        
        for (int j = 0; j < n; ++j) // We iterate each customer to see how many customers intersects at that hour 
            if (has_this_hour(customers[j], hour))
                customers_per_hour++;

        best_max = max(best_max, customers_per_hour);
    }

    cout << best_max << endl;

    return 0;   
}