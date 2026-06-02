#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define io_boost ios_base::sync_with_stdio(0);cin.tie(0);
using ll = long long;
using ull = unsigned long long;
const ll MAXN = 2e5 + 7;
const ll oo = numeric_limits<ll>::max();

/** @brief
 * We are given two speeches of the same length N with only uppercase A-Z of 
 * the English alphabet and we must print the longest contiguous block of 
 * characters that appears in both. If several blocks share the maximum length, 
 * any of them is accepted.
 *
 * Idea is mixing binary search on the answer + rolling hash which is a largely 
 * known algorithm to solve this problem:
 * 
 * The key observation is monotonicity: if a common substring of length L
 * exists, then a common substring of length L-1 also exists (just drop the
 * last character). So the predicate "there is a common substring of length L"
 * is true for every L up to some maximum and false afterwards. That lets us
 * binary search for the largest L instead of trying every length one by one.
 * 
 * For a fixed length L we still need to decide, quickly, whether the two
 * speeches share a window of that size. Comparing windows character by
 * character would be too slow, so we fingerprint every window with a rolling
 * hash. A rolling hash turns any substring into a single number in O(1) once
 * we have precomputed the prefix hashes, so we can collect every length-L
 * fingerprint of the first speech into a hash set and then scan the second
 * speech asking "have I seen this fingerprint before?".
 * 
 * To avoid collisions we use two different substrings landing 
 * on the same number, basically we use a double hash: two independent (base, modulus)
 * pairs combined into one 64-bit key. With N up to 1e5 and many comparisons a
 * single hash would be risky, so the second hash is what keeps the answer safe.
 *
 * Complexity:
 * - Building the prefix hashes is a single linear pass per speech: O(N).
 * - Each predicate check (the lambda `check`) builds the set from the first
 *   speech and scans the second speech, each window costing O(1) thanks to the
 *   precomputed hashes, so one check is O(N).
 * - Binary search runs that check O(log N) times.
 * => Total time: O(n.log(n)).
 * => Memory: O(n) for the prefix-hash arrays and the hash set.
 */

// Two moduli and two bases so we can build a double hash, this makes the chance
// of two different substrings colliding on the same key negligible.
const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;
const ll BASE1 = 131;
const ll BASE2 = 137;

// Builds the prefix hashes and the powers of the base for a string.
// h[i] = hash of the prefix s[0..i-1].  pw[i] = base^i mod M.
void build(const string &s, ll base, ll mod, vector<ll> &h, vector<ll> &pw)
{
    ll n = s.size();
    h.assign(n + 1, 0);
    pw.assign(n + 1, 1);

    for (ll i = 0; i < n; i++)
    {
        h[i + 1] = (h[i] * base + (s[i] - 'A' + 1)) % mod;
        pw[i + 1] = (pw[i] * base) % mod;
    }
}

// Hash of the substring s[i .. i+len-1] using the precomputed prefix hashes.
ll sub_hash(const vector<ll> &h, const vector<ll> &pw, ll i, ll len, ll mod)
{
    return ((h[i + len] - h[i] * pw[len]) % mod + mod) % mod;
}

int main()
{
    io_boost;

    ll n; cin >> n;
    string first_speach; cin >> first_speach;
    string sec_speach; cin >> sec_speach;

    // Prefix hashes of both speeches, one pair of arrays per (base, modulus).
    vector<ll> h1a, p1a, h1b, p1b; // first speech
    vector<ll> h2a, p2a, h2b, p2b; // second speech
    build(first_speach, BASE1, MOD1, h1a, p1a);
    build(first_speach, BASE2, MOD2, h1b, p1b);
    build(sec_speach,   BASE1, MOD1, h2a, p2a);
    build(sec_speach,   BASE2, MOD2, h2b, p2b);

    // Checks whether a common substring of length `len` exists.
    // Returns its starting position in the second speech, or -1 if none exists.
    auto check = [&](ll len) -> ll
    {
        if (len == 0) return 0;

        // Store the combined fingerprint of every length-len window of the first speech.
        unordered_set<ull> seen;
        seen.reserve((first_speach.size() - len + 1) * 2);

        for (ll i = 0; i + len <= (ll)first_speach.size(); i++)
        {
            ull key = (ull)sub_hash(h1a, p1a, i, len, MOD1) * MOD2
                    + (ull)sub_hash(h1b, p1b, i, len, MOD2);
            seen.insert(key);
        }

        // Scan the second speech looking for a window with a matching fingerprint.
        for (ll i = 0; i + len <= (ll)sec_speach.size(); i++)
        {
            ull key = (ull)sub_hash(h2a, p2a, i, len, MOD1) * MOD2
                    + (ull)sub_hash(h2b, p2b, i, len, MOD2);

            if (seen.count(key)) return i; // starting index inside the second speech
        }
        return -1;
    };

    // Binary search on the length of the common substring.
    ll lo = 0, hi = min(first_speach.size(), sec_speach.size());
    ll best_len = 0, best_pos = 0;

    while (lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        ll pos = check(mid);

        if (pos != -1)
        {
            best_len = mid;
            best_pos = pos;
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
    }

    cout << sec_speach.substr(best_pos, best_len) << endl;

    return 0;
}