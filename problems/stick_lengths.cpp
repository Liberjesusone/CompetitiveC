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
 * There are n sticks with some lengths. Your task is to modify the sticks so that each stick has the same length.
 * You can either lengthen and shorten each stick. Both operations cost x where x is the difference between the new and
 * original length.
 * What is the minimum total cost?
 * 
 * - Input
 * The first input line contains an integer n: the number of sticks.
 * Then there are n integers: p_1,p_2,...,p_n: the lengths of the sticks.
 * 
 * - Output
 * Print one integer: the minimum total cost.
 * Constraints
 * 
 * 1 <= n <= 2.10^5
 * 1 <= p_i <= 10^9
 * 
 * Example
 * Input:
 * 5
 * 2 3 1 5 2
 * 
 * Output:
 * 5
 */

/** @brief                                                                                                                     
 * Median solution: the value that minimizes the sum of absolute differences is                                               
 * always the median, not the mean.                                                                                         
 *                                                                                                                          
 * Key insight: the mean minimizes sum of SQUARED differences (quadratic cost).                                               
 * This problem uses linear cost |p_i - x|, so the median is optimal.                                                         
 * Intuition: at any non-median point, more sticks are on one side than the other —                                           
 * moving one step toward the majority always reduces total cost, until you reach                                             
 * the median where both sides balance out.                                                                            
 *                                                                                                                     
 * Sort the array, pick the middle element (or average of two middles for even n),                                     
 * then sum |p_i - median| for all sticks. O(n log n)                                                                                                                                                                       
 */  
int main()
{
    io_boost;

    ll n; cin >> n;

    vector<ll> sticks(n);
    for (ll i = 0; i < n; ++i)
    {
        cin >> sticks[i];
    }
    sort(sticks.begin(), sticks.end());

    ll median;
    n % 2 != 0 ? 
        median = sticks[n / 2] : 
        median = (sticks[(n/2)-1] + sticks[n/2]) / 2;
    
    auto cost = [median](ll stick) // returns the cost of modifing the stick
    {
        ll diference = abs(stick - median); 
        return diference;
    };

    ll min = 0;
    for (ll i = 0; i < n; ++i)
    {
        min += cost(sticks[i]);
    }

    cout << min << endl;

    return 0;
}