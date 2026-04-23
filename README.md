# Porpuse

The porpuse of this project is to store all the files and programs used to do competitive coding problems in diferent kinds of languages but starting in c++.

## Explanation of the header of each file

````c++
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
````

- The #include <bits/stdc++.h> is a header in GCC linux for competitve porpuses, that allows to include a lot of useful headers for the common coding problems, but as we are not using GCC, we are just emulating it.
- The define endl is used to avoid using std::endl that clears the buffer and it's slower.
- We use long long to avoid overflows.
- The io_bost is meant to unlink c and c++ for better performance.
- The MOD is a long long const that stores the common upper limit of entries that those problems tend to have 10^9 + 7.
- The MAXN is another common upper limit.
- The oo limit represents a infinit number in some way, is the maximun capacity of a long long: 2^63 - 1.
