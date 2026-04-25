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
 * There are n applicants and m free apartments. Your task is to distribute the apartments so that as many applicants as possible 
 * will get an apartment.
 * Each applicant has a desired apartment size, and they will accept any apartment whose size is close enough to the desired size.
 * 
 * - Input
 * The first input line has three integers n, m, and k: the number of applicants, the number of apartments, and the maximum 
 * allowed difference.
 * The next line contains n integers a_1, a_2, ... , a_n: the desired apartment size of each applicant. If the desired size
 * of an applicant is x, they will accept any apartment whose size is between x-k and x+k.
 * The last line contains m integers b_1, b_2, ... , b_m: the size of each apartment.
 * 
 * - Output
 * Print one integer: the number of applicants who will get an apartment.
 * Constraints
 * 
 * 1 <= n, m <= 2.10^5
 * 0 <= k <= 10^9
 * 1 <= a_i, b_i <= 10^9
 * 
 * Example
 * Input:
 * 4 3 5
 * 60 45 80 60
 * 30 60 75
 * 
 * 45 60 60 80
 * 30 60 75
 * 
 * Output:
 * 2
 */


// In order to solve this problem we order the apartments sizes, and the desired sizes, so that we have an indx correlation, so
// probably the smallest desired sizes will mathc the smallest apartment size, but if no we look the next apartment, with the samen 
// person and if a match has happend we continue with the following person (desired size)
// We have to sort two arrays of n and m sizes so its O(n.log(n)) + O(m.log(m)) and we iterate in the worse case, the largest array
// So assuming that n is the largest array and we have to iterate it completly the time complexity is O(n.log(n)) and the space O(n)
int main()
{
    io_boost;

    ll n, m, k; cin >> n; cin >> m; cin >> k;

    vector<ll> desired_sizes(n);
    vector<ll> apartments(m);

    for (int i = 0; i < n; ++i)
        cin >> desired_sizes[i];
    for (int i = 0; i < m; ++i)
        cin >> apartments[i];

    sort(desired_sizes.begin(), desired_sizes.end());
    sort(apartments.begin(), apartments.end());

    ll persons_assing = 0;
   
    for (int i = 0, j = 0; i < n && j < m; ++i)
    {
        if (desired_sizes[i] - k <= apartments[j] && apartments[j] <= desired_sizes[i] + k)
        {
            ++persons_assing;
            ++j;
        }           
        else if (apartments[j] < desired_sizes[i])
        {
            --i;
            ++j;
        }
    }

    cout << persons_assing << endl;

    return 0;
}