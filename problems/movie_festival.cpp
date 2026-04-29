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
 * In a movie festival n movies will be shown. You know the starting and ending time of each movie. What is the maximum 
 * number of movies you can watch entirely?
 * 
 * - Input
 * The first input line has an integer n: the number of movies.
 * After this, there are n lines that describe the movies. Each line has two integers a and b: the starting and 
 * ending times of a movie.
 * 
 * - Output
 * Print one integer: the maximum number of movies.
 * 
 * - Constraints
 * 1 <= n <= 2.10^5
 * 1 <= a < b <= 10^9
 * 
 * Example
 * Input:
 * 3
 * 3 5
 * 4 9
 * 5 8
 * 
 * Output:
 * 2
 */

/**
 * Greedy solution: sort movies by END time, then scan once.
 *
 * Key insight: among all movies you can watch right now, always pick the one
 * that ends earliest — it frees up your time the soonest, leaving the most
 * room for future movies. Any other choice can only do equal or worse.
 *
 * Track only `current_movie` (last watched). For each next movie in order,
 * if it starts >= current end time, watch it. O(n log n) sort + O(n) scan.
 */
int main()
{
    io_boost;

    ll n; cin >> n;

    vector<pair<ll, ll>> movies(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> movies[i].first; cin >> movies[i].second;
    }

    // We sort it acording to the leaving time
    sort(movies.begin(), movies.end(), [](pair<ll, ll> pair1, pair<ll, ll> pair2)
    {
        return pair1.second < pair2.second;
    });

    ll max = 1;
    auto current_movie = movies[0]; 
    for (int i = 1; i < n; ++i)
    {
        if (current_movie.second <= movies[i].first) // If we can see this movie we see it
        {
            ++max;
            current_movie = movies[i];
        }
    }

    cout << max << endl;

    return 0;
}