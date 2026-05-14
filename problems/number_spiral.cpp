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
 * A number spiral is an infinite grid whose upper-left square has number 1. Here are the first five layers of the spiral:
 * 
 * Your task is to find out the number in row y and column x.
 * 
 * -Input
 * The first input line contains an integer t: the number of tests.
 * After this, there are t lines, each containing integers y and x.
 * 
 * - Output
 * For each test, print the number in row y and column x.
 * Constraints
 * 
 * 1 <= t <= 10^5
 * 1 <= y,x <= 10^9
 * 
 * Example
 * Input:
 * 3
 * 2 3
 * 1 1
 * 4 2
 * 
 * Output:
 * 8
 * 1
 * 15
 */

int main()
{
    io_boost;

    ll t; cin >> t; 

    auto GetNumber = [](ll y, ll x) -> ll 
    {
        ll maximun = max(y,x);
        ll diagonal_number = (maximun-1)*maximun + 1;
        bool is_going_right = maximun % 2 != 0? true : false; // if x is odd is going right
        ll diff = abs(y-x);
        if (x > y)
        {   
            is_going_right? 0 : diff *= -1; 
        }
        else if (y > x)
        {
            is_going_right? diff *= -1 : 0;
        }
        
        return diagonal_number + diff;
    };

    ll x, y;
    for (ll i = 0; i < t; ++i)
    {
        cin >> y; cin >> x;
        cout << GetNumber(y, x) << endl;
    }

    return 0;
}

/*
25
1 1
1 2
1 3
1 4
1 5
2 1
2 2
2 3
2 4
2 5
3 1
3 2
3 3
3 4
3 5
4 1
4 2
4 3
4 4
4 5
5 1
5 2
5 3
5 4
5 5

*/