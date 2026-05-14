#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define io_boost ios_base::sync_with_stdio(0);cin.tie(0);
using ll = long long;
using ull = unsigned long long;
using ld = long double;
const ll MOD = 1e9 + 7;
const ll MAXN = 2e5 + 7;
const ll oo = numeric_limits<ll>::max();
const ld doo = numeric_limits<ld>::max();


/** @brief
 * Time limit: 1.00 s
 * Memory limit: 512 MB
 * 
 * Your task is to divide the numbers 1,2,...,n into two sets of equal sum.
 * 
 * - Input
 * The only input line contains an integer n.
 * 
 * - Output
 * Print "YES", if the division is possible, and "NO" otherwise.
 * After this, if the division is possible, print an example of how to create the sets. First, print the number of elements in 
 * the first set followed by the elements themselves in a separate line, and then, print the second set in a similar way.
 * 
 * Constraints
 * 1 <= n <= 10^6
 * 
 * Example 1
 * Input:
 * 7
 * 
 * Output:
 * YES
 * 4
 * 1 2 4 7
 * 3
 * 3 5 6
 * Example 2
 * Input:
 * 6
 * 
 * Output:
 * NO
 */
int main()
{
    io_boost;

    ll n; cin >> n;        
    ld w = n*(n+1) / 4;   // Total weigth is n(n+1)/2 = T 
    if (n*(n+1) % 4 != 0) // If cannot create a two sets with T/2 weigths, because T/2 is not even, it means it's not possible
    {
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;

    set<ll> numbers; 
    ll sum = 0; 
    for (ll i = n; i > 0; --i)     // 10 -> W = 33
    {                              // 10 + 9 + 8 = 27   w-sum = 6, and current = i-1 = 7, so it means we have available 6  
        if (w-sum <= (i-1))        // who can complete the sum = w
        {
            if (w == sum) break;   // if it's 0 the number we are trying to insert
            numbers.insert(w-sum);
            break;
        }
        numbers.insert(i);
        sum += i;
    }    

    cout << numbers.size() << endl; // print the first array decreasing
    for (auto val : numbers)
        cout << val << " ";

    cout << endl << n - numbers.size() << endl; // print the second array with the rest of the numbers
    for(ll i = 1; i <= n; ++i)
        cout << (numbers.contains(i) ? "" : to_string(i) + " ");


    return 0; 
}