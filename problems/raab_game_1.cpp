#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define io_boost ios_base::sync_with_stdio(0);cin.tie(0);
using ll = long long;
using ull = unsigned long long;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll MAXN = 2e5 + 7;
const ll oo = numeric_limits<ll>::max();

/** @brief
 * In order to solve this problem we have to recreate the two arrays of cards, and following the rules of the game
 * if they have n cards and a + b points, that mean that n - points is the amount of cards that they have repeated
 * so we can put a decreasing array "first" as an initial array, and then operate the other array in order to match
 * the corresponding final stats so the "second" array will be filled following this structure 
 * the ties as the same number of the "first" array 
 * the losses as an increasing sub array starting at 1, as "first" is decreasing it's going to be bigger than "second" 
 * the winnings as a decreasing sub array starting from the bigest number we have left til that point
 * 
 * As we only have to reacive the information and iterate it is O(n) time complexity and O(1) space
 */
int main()
{
    io_boost;
    ll t; cin >> t;

    for (int i = 0; i < t; ++i)
    {
        bool was_swaped = false;
        ll a, b, n;
        cin >> n; 
        cin >> a; cin >> b; 
        if (a > b) 
        {
            swap(a, b); // in order to make "a" always smaller
            was_swaped = true;
        }

        if (a + b > n || (a == 0 && b != 0))
        {
            cout << "NO" << endl;
            continue;
        }
    
        ll ties = n - (a + b); // the number of ties

        vector<ll> first;
        vector<ll> second;

        for (ll i = n; i > 0; --i) first.push_back(i);                 // first array decrecing 5 4 3 2 1
        for (ll i = n; i > n-ties; --i) second.push_back(i);           // then we fill all the ties as equals values
        for (ll i = 1; i <= a; ++i) second.push_back(i);               // then we fill all losses 
        for (ll i = 0; i < b; ++i) second.push_back(n-ties-i);         // then we fill all winnings 

        if (was_swaped) 
        {
            cout << "YES" << endl;
            for (ll val : second)
                cout << val << " ";
            cout << endl;
            for (ll val : first)
                cout << val << " ";
            cout << endl;
            continue;
        } 

        cout << "YES" << endl;
        for (ll val : first)
            cout << val << " ";
        cout << endl;
        for (ll val : second)
            cout << val << " ";
        cout << endl;
        
    }

    return 0;
}


class number
{
    public: 
        ll n;
        ll a;
        ll b;
        bool was_swaped{false};
};


int first_attempt()
{
    io_boost;
    ll t; cin >> t;

    vector<number> test_cases(t);
    for (int i = 0; i < t; ++i)
    {
        number num;
        cin >> num.n; 
        cin >> num.a; cin >> num.b; 
        if (num.a > num.b) 
        {
            swap(num.a, num.b); // in order to make a always smaller
            num.was_swaped = true;
        }
        test_cases[i] = num;
    }

    for (auto c : test_cases) // For every test case
    {
        ll a = c.a, b = c.b, n = c.n;

        if (a + b > n || (a == 0 && b != 0))
        {
            cout << "NO" << endl;
            continue;
        }
    
        ll ties = n - (a + b); // the number of ties

        vector<ll> first;
        vector<ll> second;

        for (ll i = n; i > 0; --i) first.push_back(i);                 // first array decrecing 5 4 3 2 1
        for (ll i = n; i > n-ties; --i) second.push_back(i);           // then we fill all the ties as equals values
        for (ll i = 1; i <= a; ++i) second.push_back(i);               // then we fill all losses 
        for (ll i = 0; i < b; ++i) second.push_back(n-ties-i);         // then we fill all winnings 

        if (c.was_swaped) 
        {
            cout << "YES" << endl;
            for (ll val : second)
                cout << val << " ";
            cout << endl;
            for (ll val : first)
                cout << val << " ";
            cout << endl;
            continue;
        } 

        cout << "YES" << endl;
        for (ll val : first)
            cout << val << " ";
        cout << endl;
        for (ll val : second)
            cout << val << " ";
        cout << endl;
        
    }

    return 0;
}