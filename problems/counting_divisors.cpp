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
 * Given n integers, your task is to report for each integer the number of its divisors.
 * For example, if x=18, the correct answer is 6 because its divisors are 1,2,3,6,9,18.
 * 
 * - Input
 * The first input line has an integer n: the number of integers.
 * After this, there are n lines, each containing an integer x.
 * 
 * - Output
 * For each integer, print the number of its divisors.
 * 
 * - Constraints
 * 1 <= n <= 10^5 = 100 000
 * 1 <= x <= 10^6 = 1 000 000    = 10^11 = 100 000 000 000 
 * 
 * Example
 * Input:
 * 3
 * 16
 * 17
 * 18
 * 
 * Output:
 * 5
 * 2
 * 6
 */


/** @brief 
 * This creates an array with all divisors of the numbers til 1e6 + 1 
 * to every j position that is multiple of i, we add 1
 * Because for i = 1 every number is divisible by 1 we add it to every number
 * but for i = 2 just the numbers 2*i are divisible by 2, so we add j += i on every iteration
 * for i = 3 every number in positions separated by 3 slots are divisible by 3
 * 
 * After that we just take the value we need
 * 
 * so its O(n ln(n)) and O(n) space 
 */
int main()
{
    io_boost;

    const int MAXV = 1e6 + 1;
    int div_count[MAXV] = {};
    for (int i = 1; i < MAXV; i++)
        for (int j = i; j < MAXV; j += i)
            div_count[j]++;

    ll n, val; cin >> n;
    while (n--) 
    {
        cin >> val;
        cout << div_count[val] << endl;
    }
}


set<ll> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

ll get_k(ll prime) noexcept
{
    if ((prime + 1) % 6 == 0) return (prime + 1) / 6;
    else if ((prime - 1) % 6 == 0) return (prime - 1) / 6;
}

// proves if a is prime by triying to divide it by all possibles primes with the 6k+-1 structure 
bool is_prime(ll a) noexcept
{
    if (primes.contains(a)) return true;
    if (a < 29) return false;

    ll max_prime = 0;
    for (auto _prime : primes) // to see if its divisible by one the already precalculated primes
    {
        if (a % _prime == 0) return false;
        max_prime = max(max_prime, _prime);
    }
    
    ll limit = sqrt(a);
    ll k = get_k(max_prime);
    bool is_minus = true;
    for (ll prime = max_prime; prime <= limit;) // we prove every prime which follows the structure 6k +-1 in (3, oo)
    {
        if (a % prime == 0) // if a is divisible by a prime number
            return false;

        if (is_minus) // the next possible prime
        {
            prime = 6*k + 1;
            is_minus = false;
        }
        else 
        {
            ++k;
            is_minus = true;
            prime = 6*k - 1;
        }
    }
    return true;
}

// precalculates all the primes numbers till sqrt(n)
void precalculate_primes(ll n, bool put_limit = false) noexcept
{
    ll limit;
    put_limit ? limit = sqrt(n) : limit = n; 

    ll k = 1;
    bool is_minus = true;
    for (ll prime = 31; prime <= limit;) // we prove every prime which follows the structure 6k +-1 in (3, oo)
    {
        if (is_prime(prime))
            primes.emplace(prime);

        if (is_minus)
        {
            prime = 6*k + 1;
            is_minus = false;
        }
        else
        {
            ++k;
            is_minus = true;
            prime = 6*k - 1;
        }
    }

}


// Decompose in prime factors and returns how many divisors does a has
ll count_divisors(ll a) noexcept
{
    if (a == 0) return 0;
    if (primes.contains(a)) return 2;

    map<ll, ll> primes_repetitions; // the number and it's repetitions 
    for (auto prime : primes)
    {
        if (a <= 1) break;
        while (a % prime == 0)
        {
            primes_repetitions[prime] += 1; 
            a /= prime;
        }
    }
        
    ll sum = 1;
    for (auto val : primes_repetitions)
        sum *= val.second + 1;          

    return sum;
}

// has good theory and calculates properly but takes a lot of time
int first_attempt()
{
    io_boost;

    precalculate_primes(1e6);
    ll n, val; cin >> n; 

    for (ll i = 0; i < n; ++i)
    {
        cin >> val; 
        cout << count_divisors(val) << endl;
    }

    return 0;
}