#include <bits/stdc++.h>
#include <bits/chronometer.h>
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
 * Let \sigma(n) denote the sum of divisors of an integer n. For example, \sigma(12)=1+2+3+4+6+12=28.
 * Your task is to calculate the sum \sum_{i=1}^n \sigma(i) modulo 10^9+7.
 * 
 * - Input
 * The only input line has an integer n.
 * 
 * - Output
 * Print \sum_{i=1}^n \sigma(i) modulo 10^9+7.
 * 
 * - Constraints
 * 1 <= n <= 10^{12}   
 * 
 * Example
 * Input:
 * 5
 * 
 * Output:
 * 21
 */

// Is not use but represents the logic being used to know how many numbers from [1,n] are divisible by i 
ll lema_of_dirichlet(ll i, ll n) noexcept 
{
    return n/i * i; // floor(n/i) * i;   always returns a number <= n
}

const ll modinv_2 = modinv(2);
ll summ(ll n) noexcept
{
    return multmod(n, n+1) * modinv_2 % MOD;
}

// makes the sum from the number a to b [a, b]
ll summ_intervals(ll a, ll b)
{
    return submod(summ(b), summ(a-1));
}

int main()
{
    io_boost;

    ll n, sum = 0; cin >> n;

    cronometer::clock_start();

    ll amount, right, interval;

    for (ll left = 1; left <= n;)
    {
        amount = n / left;
        right = n / amount;

        if (left < right)
        {
            interval = multmod(summ_intervals(left, right), amount);
            sum = addmod(sum, interval);
            left = right + 1;
        }
        else 
        {
            sum = addmod(sum, amount*left);
            ++left;
        }
    }

    cout << sum << endl; 
    cerr << "Tiempo: " << cronometer::clock_end() << " ms\n";

    return 0;
}