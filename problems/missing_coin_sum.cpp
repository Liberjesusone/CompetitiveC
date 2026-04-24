#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define io_boost ios_base::sync_with_stdio(0);cin.tie(0);
using ll = long long;
using ull = unsigned long long;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll MAXN = 2e5 + 7;
ll n, m, q;
const ll oo = numeric_limits<ll>::max();

/** @brief
 * Time limit: 1.00 s
 * Memory limit: 512 MB
 * 
 * You have n coins with positive integer values. What is the smallest sum you cannot create using a subset of the coins?
 * 
 * - Input
 * The first line has an integer n: the number of coins.
 * The second line has n integers x_1,x_2, ... ,x_n: the value of each coin.
 * 
 * - Output
 * Print one integer: the smallest coin sum.
 * 
 * - Constraints
 * 1 <= n <= 2.10^5
 * 1 <= x_i <= 10^9
 * 
 * Example
 * Input:
 * 5
 * 2 9 1 2 7
 * 
 * Output:
 * 6
 */


/** @brief  For this method we use the following logic:
 *  
 * if we have only int+, the smallest number possible is 1 
 * if we have 1 in the secuence thats our initial value we only are able to create   [1]
 * if the next one is 2 we will be able to create 1+2=3 and 1                      = [1,2,3]
 * then the next one like 3 we will be able to create 1,2,3, 1+3, 2+3, (1+2= 3)+3  = [1,2,3,4,5,6]
 * then the next one e.g 4 [1,2,3,4,5,6, 3+4, 4+4, 5+4, 6+4]                       = [1,2,3,4,5,6,7,8,9,10]
 * then the next one e.g 5 [1,2,3,4,5,6, 3+4, 4+4, 5+4, 6+4]                       = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15]
 * 
 * so this patters follows a rule, if we are sure that we can create a number by summing from 1 to k [1,k]
 * and then we add a number c to our list that is c <= k+1 we will be able to create then k+c numbers [1,k+c]
 * that k or k+c is the smallest sum we can create with a given list, because not every number of a list machest that constraint
 * if the number c > k+1, we will nor be able to create the k+1 element, knowing that at that momento we have the range [1,k]
 * a c greater that k+1 even if its just k+2 can only sum up to k+3 with the combination 1+c = 1+k+2 = k+3 so the in order
 * to expand the range we will need the k+1 and the k+2 elements, only reacheable with c that maches c <= k+1
 * 
 * so we first of all put the coins in order, and we iterate them looking if they meet the condition if not we are sure that is 
 * c > k+1 so we are not gonna find any other coin that meets that condition and we will have found the smallest sum
 */
int main()
{
    io_boost;

    ll n; cin >> n;
    vector<ll> coins(n);
    for (int i = 0; i < n; ++i) // we recive the coins values
        cin >> coins[i];

    sort(coins.begin(), coins.end()); // we sort the array

    ll smallest_sum = 0; // the smallest sum possible

    for (int i = 0; i < n; ++i)
    {
        if (coins[i] <= smallest_sum + 1) 
            smallest_sum += coins[i];   
        else 
            break;
    }

    cout << smallest_sum + 1 << endl;

    return 0;
}