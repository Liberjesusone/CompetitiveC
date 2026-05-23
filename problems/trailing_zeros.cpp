#include <bits/stdc++.h>
//#include <bits/chronometer.h>
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
 * Your task is to calculate the number of trailing zeros in the factorial n!.
 * For example, 20!=2432902008176640000 and it has 4 trailing zeros.
 * 
 * - Input
 * The only input line has an integer n.
 * 
 * - Output
 * Print the number of trailing zeros in n!.
 * Constraints
 * 
 * 1 <= n <= 10^9
 * 
 * Example
 * Input:
 * 20
 * 
 * Output:
 * 4
 */


/** @brief 
 * The greater amount of 0 there are in a number after making all the factorial process, is the amount given by all the 10,
 * that has been created in the multiplication process
 * 
 * @example 15! = 1*2*3*4*5*6*7*8*9*10*11*12*13*14*15 
 * in this example we can take all the 10 there are and also we can factorize all 2 we need to join to all the 5^exp that we have, 
 * for example 15! = 1*3*2*6*7*8*9*11*12*13*14*(10)*(15*2)*(5*2)      
 * this way we created 15! =  1*3*2*6*7*8*9*11*12*13*14*(10)*(30)*(10)      
 *                     15! =  1*3*2*6*7*8*9*11*12*13*14*(10)*(3*10)*(10)      
 *                     15! =  1*3*3*2*6*7*8*9*11*12*13*14*(10)^3 
 * So that means there will be at least 3 ceros at the begining of the result number
 * So for every power of 5 we will have a 0 and the same for every power of 10 as they are divisible by 5 is like counting 
 * another five, so the amount of numbers divisible by five in n are the amount of 0 there will be, but we have to also take
 * into account the numbers between [1,n] that are divisible by a power of five, because they have more than one 5 and 
 * with the first division we only focus on the first five, but dividing by n/5^2 gives us the amoung of numbers that have 2 fives
 * so for every n/5^{power} we will have another amount of 0, so we take the sum = n/5^1 + n/5^2 + n/5^3 + .... + n/5^exp       
 */
int main()
{
    ull n, count = 0, current; cin >> n; 
    ull div5 = 5; // evaluates all the exponents 
    for (ull i = 0; div5 <= n; ++i)
    {
        current = n / div5;
        if (current == 0) break;
        count += current; 
        div5 *= 5;   // the next power of 5
    }

    cout << count << endl;
    
    return 0; 
}




// Obvious solution, off course, so slow
int first_attempt()
{
    io_boost; 

    ll n, num = 1; cin >> n;

    for (ll i = 2; i <= n; ++i)
        num *= i;

    string number_str = to_string(num);   
    ll count = 0, _max = 0; 
    for (ll i = 0; i < number_str.size(); ++i)
    {
        if (number_str[i] == '0')
        {
            ++count;
            _max = max(_max, count);
        }
        else 
            count = 0;
    }   

    cout << count << endl;
    return 0;
}