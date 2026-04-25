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
 *
 * Time limit: 1.00 s
 * Memory limit: 512 MB
 * 
 * There are n children who want to go to a Ferris wheel, and your task is to find a gondola for each child.
 * Each gondola may have one or two children in it, and in addition, the total weight in a gondola may not exceed x. You know the weight of every child.
 * What is the minimum number of gondolas needed for the children?
 * 
 * - Input
 * The first input line contains two integers n and x: the number of children and the maximum allowed weight.
 * The next line contains n integers p_1,p_2,\ldots,p_n: the weight of each child.
 * 
 * - Output
 * Print one integer: the minimum number of gondolas.
 * Constraints
 * 
 * 1 <= n <= 2.10^5
 * 1 <= x <= 10^9
 * 1 <= p_i <= x
 * 
 * Example
 * Input:
 * 4 10
 * 7 2 3 9
 * 
 * Output:
 * 3 
 */


// the heaviest person (persons[right]) must always get a gondola. The only question is
// whether the lightest available person can share it. If yes, pair them (left++). Either way, right-- and count 1 gondola.
// As we only have to sort the array and iterate it it will be O(n.log(n)) time complexity and O(n) space
int main()
{
    io_boost;

    ll n, x; cin >> n; cin >> x;

    vector<ll> persons(n);
    for (int i = 0; i < n; ++i)
        cin >> persons[i];

    sort(persons.begin(), persons.end());

    ll gondolas = 0;
    int left = 0, right = n - 1;

    while (left <= right)
    {
        if (persons[left] + persons[right] <= x)
            ++left;
        --right;
        ++gondolas;
    }

    cout << gondolas << endl;

    return 0;
}

int main2()
{
    io_boost;

    ll n, x; cin >> n; cin >> x;

    vector<ll> persons(n); 
    for (int i= 0; i < n; ++i)
        cin >> persons[i];

    sort(persons.begin(), persons.end());

    ll cars = 0;
    ll sum = persons[n - 1];
    int childrens = 1;
    bool was_added = false; 

    for (auto value : persons)
        cout << value << " ";
    cout << endl;

    for (int i = 0, j = n-2; i <= j;)
    {
        cout << "We are at i: " << i << "=" << persons[i] << "   - j:" << j << "=" << persons[j] << endl;
        cout << " - sum: " << sum << endl;

        if (i == j)
        {
            cout << "Sum final " << sum << "    i: " << i << "   - j: " << j << endl;
            sum += persons[i]; 
            cout << "- persons[i]: " << persons[i] << endl;
            if (sum <= x) ++cars;
            else cars += 2;
            sum = 0;
            break;
        }

        if (sum + persons[j] <= x && childrens < 2) // if summing the heaviest person is possible
        {
            cout << "we sum: " << persons[j] << endl;    
            sum += persons[j];
            --j;
            ++childrens;
            was_added = true;
        }
        if (sum + persons[i] <= x && childrens < 2) // if summing the thinnest person is possible
        {
            cout << "we sum: " << persons[i] << endl;
            sum += persons[i];
            ++i;
            ++childrens;
            was_added = true;
        }
        
        if (!was_added) // it means that the current sum cannot hold any other passenger
        {
            ++cars;
            sum = 0;
            childrens = 0;
            cout << "Was added Count: " << cars << endl;
            continue;
        }

        sum == x ? ++cars, sum = childrens = 0 : 0; // if the sum completes a car we count it
        if (sum == 0) cout << "Was reset Count: " << cars << endl;
        was_added = false;
    
    }
    if (sum != 0) ++cars;

    cout << cars << endl;

    return 0;
}