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


namespace Module
{
    long long binpow(long long base, long long exp, long long mod = 1e9 + 7) noexcept
    {
        long long result = 1;
        base %= mod;
        while (exp > 0) // if exp = 0000000 binary 
        {
            if (exp & 1)    // if the less significant bit is 1
                result = result * base % mod;
            base = base * base % mod;
            exp >>= 1;      // right shift = divide by 2 -> displace one bit to right
        }
        return result;
    }

    long long addmod(long long a, long long b, long long mod = 1e9 + 7) noexcept
    {
        return (a % mod + b % mod) % mod;
    }

    long long submod(long long a, long long b, long long mod = 1e9 + 7) noexcept
    {
        return (a % mod - b % mod + mod) % mod;
    }

    long long multmod(long long a, long long b, long long mod = 1e9 + 7) noexcept
    {
        return ((a % mod) * (b % mod)) % mod;
    }

    // Fermat small theorem: b*b^{-1} = 1 mod m  ->   b^{-1} = b^{MOD - 2} % MOD       if MOD is prime 
    long long modinv(long long b, long long mod = 1e9 + 7) noexcept
    {
        return binpow(b, mod - 2, mod);
    }

    long long divmod(long long num, long long div, long long mod = 1e9 + 7) noexcept
    {
        return num % mod * modinv(div, mod) % mod;
    }

    const int MAX_FACT = 1e6 + 5; // 1 000 005
    long long fact[MAX_FACT], inv_fact[MAX_FACT];

    // Calculates all values for factorials and their modular inverses till 1 000 005 in the variables fact[], inv_fact[]
    void precompute(long long mod = 1e9 + 7)
    {
        fact[0] = 1;
        for (int i = 1; i < MAX_FACT; i++)
            fact[i] = fact[i-1] * i % mod;
        
        inv_fact[MAX_FACT-1] = modinv(fact[MAX_FACT-1], mod);
        for (int i = MAX_FACT-2; i >= 0; i--)
            inv_fact[i] = inv_fact[i+1] * (i+1) % mod;
    }

    // Combination: binomial coefficient
    long long C(long long n, long long k, long long mod = 1e9 + 7) 
    {
        if (k < 0 || k > n) return 0;
        return fact[n] % mod * inv_fact[k] % mod * inv_fact[n-k] % mod;
    }
}
using namespace Module;


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

    chronometer::clock_start();

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
    cerr << "Tiempo: " << chronometer::clock_end() << " ms\n";

    return 0;
}