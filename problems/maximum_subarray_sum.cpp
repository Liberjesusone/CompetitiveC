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

// https://cses.fi/problemset/task/1643
// Maximum Subarray Sum
// Find the maximum sum of a contiguous, nonempty subarray.
// 
// This is the Kadane's algorithm, which runs in O(n) time and O(1) space.

/** @brief
 * Time limit: 1.00 s
 * Memory limit: 512 MB
 * 
 * Given an array of n integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.
 *
 * - Input
 * The first input line has an integer n: the size of the array.
 * The second line has n integers x_1,x_2, ... ,x_n: the array values.
 * 
 * - Output
 * Print one integer: the maximum subarray sum.
 * Constraints
 * 
 * 1 <= n <= 2.10^5
 * -10^9 <= x_i <= 10^9
 * 
 * Example
 * Input:
 * 8
 * -1 3 -2 5 3 -5 2 2
 * 
 * Output:
 * 9
 */

int main() 
{
    io_boost;

    ll n, sum, best; 
    cin >> n;                           // We read the size of the array.
    vector<ll> x(n);

    for (int i = 0; i < n; i++) cin >> x[i];   // We read the array values.

    sum = best = x[0];                     // We initialize sum and best with the first element of the array.
    for (int i = 1; i < n; i++)            // For each element in the array starting from the second one, we update sum and best.
    {                                      // If the current element is greater than the sum of the previous ones, we are gonna         
        sum = max(x[i], sum + x[i]);       // start a new subarray from the current element. Otherwise, we continue the current 
        best = max(best, sum);             // subarray by adding the current element to the sum.
    }                                      // And the best is just the maximum sum we have found so far. 

    cout << best << endl;
}