#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
//#include <bits/chronometer.h>
//using namespace chronometer;
#define io_boost ios_base::sync_with_stdio(0);cin.tie(0);
using ll = long long;
using ull = unsigned long long;
const ll MOD = 1e9 + 7;
const ll MAXN = 2e5 + 7;
const ll oo = numeric_limits<ll>::max(); // 2*10^10


/// # Time limit: 1.00 s
/// # Memory limit: 512 MB
/// 
/// Given a string, your task is to reorder its letters in such a way that it becomes a
/// palindrome (i.e., it reads the same forwards and backwards).
/// 
/// # Input
/// The only input line has a string of length n consisting of characters A–Z.
/// 
/// # Output
/// Print a palindrome consisting of the characters of the original string. You may print
/// any valid solution. If there are no solutions, print "NO SOLUTION".
/// 
/// # Constraints
/// 
/// 1 <= n <= 10^6
/// 
/// # Example
/// ## Input:
/// AAAACACBA
/// 
/// ## Output:
/// AACABACAA 
int main()
{
    io_boost;
    
    char letter;                  // current letter
    string halfString = "";       
    unordered_map<char, ull> map; // the char and the times it is repeated
    unordered_set<char> oddChars; // chars that only appears once

    while (cin.get(letter) && letter != '\n') // we read letter by letter to improve performance
    {
        if (map.contains(letter) && map[letter] % 2 != 0) halfString += letter; // for every odd char we added to the left half 

        ++map[letter];            // fill the map    
        
        if (map[letter] % 2 != 0) // If it's odd
            oddChars.insert(letter);
        else                      // if it's even
            oddChars.erase(letter);
    }

    if (oddChars.size() <= 1) // if it's 0 all are even so it's simetric, if one is odd, that odd char could be the middle 
    {
        cout << halfString << (oddChars.size() == 1 ? string(1, *oddChars.begin()) : "");  // half of the string and the middle
        reverse(halfString.begin(), halfString.end());                                     // we reverse the other half
        cout << halfString << endl;
    }
    else cout << "NO SOLUTION" << endl; 

    return 0;
}