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
 * There are n apples with known weights. Your task is to divide the apples into two groups so that the difference
 * between the weights of the groups is minimal.
 *
 * - Input
 * The first input line has an integer n: the number of apples.
 * The next line has n integers p_1,p_2,...,p_n: the weight of each apple.
 *
 * - Output
 * Print one integer: the minimum difference between the weights of the groups.
 *
 * - Constraints
 * 1 <= n <= 20
 * 1 <= p_i <= 10^9
 *
 * Example
 * Input:
 * 5
 * 3 2 7 4 1
 *
 * Output:
 * 1
 *
 * Explanation: Group 1 has weights 2, 3 and 4 (total weight 9), and group 2 has weights 1 and 7 (total weight 8).
 */

/** @brief
 * To solve this problem we use bitmask enumeration to check all possible partitions.
 *
 * For a partition into two groups, if one group has sum W and the total is T,
 * the other group has sum T-W, so the difference is W-(T-W) = 2W-T.
 * We want to minimize |2W - T| over all possible subsets W.
 *
 * Since every partition {A, B} is the same as {B, A}, we only need to check half
 * of all 2^n subsets. We do this by fixing the last element always in group 1,
 * so we enumerate masks from 1 to 2^(n-1) — that gives us 2^(n-1) distinct partitions.
 *
 * The minimum is updated inline during enumeration, so no extra vector is needed.
 *
 * Time complexity:  O(n * 2^(n-1)) — for n=20 that's ~10 million operations, well within 1s.
 * Space complexity: O(1) — only a single result variable is kept.
 */
int main()
{
    io_boost;

    ll n; cin >> n;

    ll total = 0;
    vector<ll> weights(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> weights[i];
        total += weights[i];
    }

    if (n == 1)
    {
        cout << weights[0];
        return 0;
    }

    ll min_diff = oo;
    for (int mask = 1; mask < (1 << (n - 1)); ++mask)
    {
        ll w = 0;
        for (int i = 0; i < n; ++i)
            if (mask >> i & 1) w += weights[i];
        min_diff = min(min_diff, abs(2*w - total));  // w - (T-w) = 2w - T
    }

    cout << min_diff << endl;

    return 0;
}