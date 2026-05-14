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
 * You are given a DNA sequence: a string consisting of characters A, C, G, and T. Your task is to find the longest 
 * repetition in the sequence. This is a maximum-length substring containing only one type of character.
 * 
 * - Input
 * The only input line contains a string of n characters.
 * 
 * - Output
 * Print one integer: the length of the longest repetition.
 * Constraints
 * 
 * 1 <= n <= 10^6
 * 
 * Example
 * Input:
 * ATTCGGGA
 * 
 * Output:
 * 3
 */
int main()
{
    io_boost;

    string DNA; cin >> DNA; 

    char current = DNA[0];
    char next;
    ll maximun = 0;
    ll count = 1;
    for (int i = 1; i < DNA.size(); ++i)
    {
        next = DNA[i];
        if (current == next)
            ++count;
        else 
        {
            current = next;
            maximun = max(count, maximun);
            count = 1;
        }
    }
    maximun = max(count, maximun);
    cout << maximun << endl;

    return 0; 
}