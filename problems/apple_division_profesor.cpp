
# include <bits/stdc++.h>
using namespace std;
# define endl "\n"
# define io_boost ios_base :: sync_with_stdio(0);cin.tie(0);
using ull = unsigned long long;
using ll = long long;
const ll mod = 1e9 + 7;
const ll MAXN = 2e5 + 7;
const ll oo =numeric_limits<ll> :: max();
ll n, m, q, a[30], ans =oo;

void solve(ll g1, ll g2, int i) 
{
    if (i >= n)
    {
        ans = min(abs(g1-g2),ans);
        return;
    }   
    solve(g1+a[i], g2, i+1);
    solve(g1, g2+a[i], i+1);
}

/*
    JAUNKI
*/
int main()
{
    io_boost;
    cin >>n;
    for (int i = 0; i <n; i++) cin >> a[i];
    solve(0, 0, 0);
    cout << ans << endl;

}