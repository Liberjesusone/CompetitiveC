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
 * You are given n sticks with lengths a_1,a_2,...,a_n.
 * You must make exactly k cuts to the sticks, so that
 * the number of sticks becomes n + k.
 * 
 * After making the cuts, the difference between the length of the longest and 
 * shortest sticks should be as small as possible.
 * Your task is to compute the smallest possible difference for all amounts k=1,2,...,m.
 * The cuts must keep the lengths of the sticks positive integers. You may assume that the 
 * sticks can be cut m times.
 * 
 * - Input
 * The first line contains two integers n,m: the number of sticks and the maximum number of cuts.
 * The second line contains n integers a_1,a_2,...,a_n:
 * the lengths of the sticks.
 * 
 * - Output
 * Print one line with m integers: the smallest possible difference if exactly k=1,2,...,m cuts are made.
 * 
 * Constraints
 * 1 <= n <= 10^5
 * 1 <= m <= 2.10^5
 * 1 <= a_i <= 10^9
 * 
 * Example
 * Input:
 * 3 3
 * 7 3 2
 * 
 * Output:
 * 2 1 2
 * 
 * Explanation: When k=1, you can cut the first stick into two sticks of lengths 3 and 4. After this, the stick lengths 
 * are [3,4,3,2] and the maximum difference is 2.
 */
int main()
{
    io_boost;

    ll n, m; cin >> n; cin >> m;

    priority_queue<ll> sticks_heap;
    ll _min = oo, val;
    for (ll i = 0; i < n; ++i)
    {
        cin >> val;
        sticks_heap.emplace(val);
        _min = min(val, _min); // we take the min because in heap is O(n) to find the min
    }

    // if we make k cuts in n sticks, we are going to have at the end n+k sticks, because every cut create a new stick 
    ll first, second, top, current_min = _min;
    for (ll k = 1; k <= m; ++k) // for every m value as k=1,2,3,...,m
    {
        top = sticks_heap.top(); sticks_heap.pop();
        top % 2 == 0 ? 
            first = second = top / 2:
            (first = top / 2 + 1, second = top / 2);
        
        sticks_heap.emplace(first); sticks_heap.emplace(second);
        current_min = min(current_min, min(first, second));             
        
        cout << (sticks_heap.top() - current_min) << " ";
    }
    cout << endl;


    return 0;
}



int first_attempt()
{
    io_boost;   

    ll n, m; cin >> n; cin >> m;

    priority_queue<ll> sticks_heap;
    ll _min = oo, val;
    for (ll i = 0; i < n; ++i)
    {
        cin >> val;
        sticks_heap.emplace(val);
        _min = min(val, _min); // we take the min because in heap is O(n) to find the min
    }


    // if we make k cuts in n sticks, we are going to have at the end n+k sticks, because every cut create a new stick 
    ll first, second, top, current_min = _min;
    for (ll k = 1; k <= m; ++k) // for every m value as k=1,2,3,...,m
    {
        top = sticks_heap.top(); sticks_heap.pop();
        top % 2 == 0 ? 
            first = second = top / 2:
            (first = top / 2 + 1, second = top / 2);
        
        sticks_heap.emplace(first); sticks_heap.emplace(second);
        current_min = min(current_min, min(first, second));             
        
        cout << (sticks_heap.top() - current_min) << " ";
    }
    cout << endl;
    return 0;
}