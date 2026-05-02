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
 * There are n children and m apples that will be distributed to them. Your task is to count the number of ways this can be done.
 * For example, if n=3 and m=2, there are 6 ways: [0,0,2], [0,1,1], [0,2,0], [1,0,1], [1,1,0] and [2,0,0].
 * 
 * - Input
 * The only input line has two integers n and m.
 * 
 * - Output
 * Print the number of ways modulo 10^9+7.
 * 
 * Constraints
 * 
 * 1 <= n,m <= 10^6
 * 
 * Example
 * Input:
 * 3 2
 * 
 * Output:
 * 6
 */

/** @brief
 * In order to solve this problem we have to see the assinging part instead of a selection or permutations, as a divison of a set
 * because we can visualize the assigning part as groups, where the first person is agrouped with w amount of apples, and so on, so
 * we are going to have n-1 divisions, because if we divide n people into "groups" of just one person, we would have to divide, n-1
 * times, now we can see the division as a barrer which separates the set just like in this graph where a person is represented as
 * P, and the apples as A
 *
 * P  |P  |P  |P    |P
 * AA |A  |   |AAAA |A
 *
 * so is clearly that the amount of barrears are n-1, and the amount of elements that we are diving isn't actually the n amount of
 * people, is the amount of people and the apples, because if we see it as an array we can put the w_i amount of apples followed
 * by a P and repeat this patter to represent the previous graph in a secuential array, now how do we calculate all the assigning
 * possibilities seeing the problem this way, well we would only have to calculate in how many positions can we place all the
 * available barrears, because a given combination of those indistinguishable barrears is a possible assigning combination.
 * So the amount of positions where we can put a barrear is the spaces in the middle of every element of the secuential array
 * that we mentioned before, so if that arrays contains n + m elements, it would be m + n -1 available positions for barrears,
 * and now we have to place n-1 amount of barrears, so this matches with the definition of a binomial coefficient C(x, y), where
 * we place "y" amount of elements in "x" amount of spaces without counting the permutations because the elements are considered
 * equals, so we only have to calculate
 *
 * C(m + n - 1, n-1)
 *                                                                                                                                      
 * (n+m-1)!       n.(n+1).(n+2)....(n+m-1)                                                                                        
 * ─────────── = ─────────────────────────
 * (n-1)! · m!               m!                                                                                                          
 *
 * Which also reduces to: n*(n+1)*...*(n+m-1) / m!
 * 
 * Avoiding calculating (n+m-1)! and (n-1)! separately because it would overflow even with mod.
 * And now to do the division we would use modular inverse: a^(MOD-2) % MOD basing on Fermat's little theorem
 * because we have enourmus numbers in the numerator and the denominator, so we cannot divide Num/Den % MOD because
 * the Num and the Den are so big, so we have the take the module of those numbers and to keep the proportions 
 * we divide this way: 
 * 
 * Num % MOD * Den^{MOD-2} = Num/Den % MOD
 * 
 * To calculate the module of n! like n! % MOD, we take the module of every multiplier an the proportions are kept because of 
 * the distributive property of module about multiplication:                                                                      
 * (a * b) % M  =  ((a % M) * (b % M)) % M      
 * 
 * And the exponential inheritates this behavior because exponential inheritates from multiplication so we use a diferent 
 * power method 
 * a^8 % M  =  (a^4 % M)^2 % M  =  ((a^2 % M)^2 % M)^2 % M
 * 
 * So the easier part is to discover the formula and then calculating module to not cause an overflow on every part of the 
 * calculation, has a different behavior  
 */
int main()
{
    io_boost;

    ll n, m; cin >> n >> m;

    // A power method to take into account the MOD
    auto power = [](ll a, ll b) -> ll 
    {
        ll res = 1;
        a %= MOD;
        while (b > 0) 
        {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    };

    // Numerator: n * (n+1) * ... * (n+m-1)
    ll num = 1;
    for (ll i = n; i <= n + m - 1; ++i)
        num = num * i % MOD;

    // Denominator: m! a normal factorial
    ll den = 1;
    for (ll i = 2; i <= m; ++i)
        den = den * i % MOD;

    cout << num * power(den, MOD - 2) % MOD << endl;

    return 0;
}