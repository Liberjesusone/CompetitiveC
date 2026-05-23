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
    // Does O(log_2(exp)) iterations
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
 * Given an integer, your task is to find the number, sum and product of its divisors. As an example, 
 * let us consider the number 12:
 * 
 * the number of divisors is 6 (they are 1, 2, 3, 4, 6, 12)
 * the sum of divisors is 1+2+3+4+6+12=28
 * the product of divisors is 1.2.3.4.6.12 = 1728
 * 
 * Since the input number may be large, it is given as a prime factorization.
 * 
 * - Input
 * The first line has an integer n: the number of parts in the prime factorization.
 * After this, there are n lines that describe the factorization. Each line has two numbers x and k 
 * where x is a prime and k is its power.
 * 
 * - Output
 * Print three integers modulo 10^9+7: the number, sum and product of the divisors.
 * Constraints
 * 
 * 1 <= n <= 10^5
 * 2 <= x <= 10^6 1 000 000
 * each x is a distinct prime
 * 1 <= k <= 10^9 1 000 000 000
 * 
 * Example
 * Input:
 * 2
 * 2 2
 * 3 1
 * 
 * Output:
 * 6 28 1728
 */



/** @brief
 * Gets a vector (v1, v2, v3, ... ,v_n) and returns the next one (v1+1,v2, v3, ... ,v_n) following the clock limits of every position (f_i)
 * 
 * The vector (f1, f2, f3, ... fn) where 0 <= fi <= ki represents the exponents of the prime factors to generate the next divisor
 * the prime factores are p_i and their exponents are k_i
 * 
 * if the first prime p1 has for k1 = 2 then f1 goes from [0,2]
 * and if the second prime p2 has for k2 = 3 then f2 goes from [0,3]
 * 
 * for (0,0,0, ...., 0_n)  = p1^{0}*p2^{0}*p3^{0}*...*pn^{0}  the next one is 
 * for (1,0,0, ...., 0_n)  = p1^{1}*p2^{0}*p3^{0}*...*pn^{0}  will return ...
 * for (2,0,0, ...., 0_n)  = p1^{2}*p2^{0}*p3^{0}*...*pn^{0}
 * for (0,1,0, ...., 0_n)  = p1^{0}*p2^{1}*p3^{0}*...*pn^{0}  f1 resets to 0 
 * for (1,1,0, ...., 0_n)  = p1^{1}*p2^{1}*p3^{0}*...*pn^{0}  
 * for (2,1,0, ...., 0_n)  = p1^{2}*p2^{1}*p3^{0}*...*pn^{0}  
 * .
 * .
 * .
 * if we reached the limit it returns (k1,k2,k3, ...., kn)  = p1^{k1}*p2^{k2}*p3^{k3}*...*pn^{kn}  
 * 
 * @remarks Does O(n) because in the worse case it has to sum 1 to the last element
 */ 
vector<ll> get_vector(vector<ll> current_vector, vector<pair<ll, ll>> divisors_exp) noexcept
{
    for (ll i = 0; i < divisors_exp.size(); ++i)
    {
        //                i
        // current value (3,0,0)   ==  f1
        if (current_vector[i] >= divisors_exp[i].second) // we reached this position limit  (it would never overpass)
        {
            current_vector[i] = 0; // we reset this position
            continue;
        }
        ++current_vector[i];
        break;
    } 
    return current_vector;
}

/** @brief
 * For a given vector (v1, v2, v3, ..., v_n) returns the divisor represented by   
 * p1^{v1}*p2^{v2}*p3^{v3}*...*pn^{v_n}    the p values are the prime bases given by the array bases_exp 
 * 
 * @remarks Does O( n log(exp)) where n is the size of current_vector and exp are the values of them
 */
ll get_div(vector<ll> current_vector, vector<pair<ll, ll>> bases_exp) noexcept
{
    ll divisor = 1;

    for (ll i = 0; i < bases_exp.size(); ++i)
    {
        if (current_vector[i] == 0) continue;
        divisor = multmod(divisor, binpow(bases_exp[i].first, current_vector[i]));  // base ^ exp
    }

    return divisor;
}

pair<ll, ll> eval(vector<pair<ll, ll>> bases_exp, ll div_quan) noexcept
{
    ll sum=1, mult=1, current_div = 1;

    vector<ll> current_vector;
    for (ll i = 0; i < bases_exp.size(); ++i)
        current_vector.push_back(0);

            // minus one because we already took into account the 1
    for (ll it = 0; it < div_quan-1; ++it)
    {
        current_vector = get_vector(current_vector, bases_exp);
        current_div = get_div(current_vector, bases_exp);

        sum = addmod(sum, current_div);
        mult = multmod(mult, current_div);
    }

    return {sum, mult};
}


int main()
{
    io_boost;

    ll n; cin >> n;                     // takes into account the common 1 divisor
    ll num = 1, base, exp, cant = 1, sum = 1, mult = 1;
    set<ll> divisors_set;

    vector<pair<ll, ll>> bases_exp; // <ll, ll> the divisor and the exponent of each one

    for (ll i = 0; i < n; ++i)
    {
        cin >> base; cin >> exp;
        
        bases_exp.push_back({base, exp});
        
        num = multmod(num, binpow(base, exp));
        cant = multmod(cant, exp + 1); 
    }
    chronometer::clock_start();
    
    auto pair = eval(bases_exp, cant);
    sum = pair.first; mult = pair.second;

    cout << "-Numero: " << num << endl 
         << "-Divisores: "<<  cant << endl 
         << "-Suma: " << sum << endl
         << "-Mult: " << mult << endl;  
    
    cerr << "tiempo " << chronometer::clock_end() << endl;

    return 0;
}