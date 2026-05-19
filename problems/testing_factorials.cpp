#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define io_boost ios_base::sync_with_stdio(0);cin.tie(0);
using ll = long long;
using ull = unsigned long long;
const ll MOD = 1e9 + 7;
const ll MAXN = 2e5 + 7;
const ll oo = numeric_limits<ll>::max();

int main()
{
    io_boost;

    precompute();

    for (ll i = 0; i < 20; i++)
        cout << "Fact: " << fact[i] << "   - inverse: " << inv_fact[i] << endl; 
    
    
    return 0;
}