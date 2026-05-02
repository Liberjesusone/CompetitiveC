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
 * Your task is to count for k=1,2,...,n the number of ways two knights can be placed on a k*k chessboard so 
 * that they do not attack each other.
 * 
 * - Input
 * The only input line contains an integer n.
 * 
 * - Output
 * Print n integers: the results.
 * 
 * - Constraints
 * 1 <= n <= 10000
 * 
 * Example
 * Input:
 * 8
 * 
 * Output:
 * 0
 * 6
 * 28
 * 96
 * 252
 * 550
 * 1056
 * 1848
 */

/** @brief 
 * In the given case, the two knights has the same color, that is so important because in a certain position, two knights can just
 * switch place counting it just as one position, because the two knights are indistinguishable, but if they had different colors
 * (So that they could attack each other) it would be count as two different permutations. So according with the results given
 * this programm should calculate the permutations with two equals knights. 
 * 
 * In order to calculate it we have to take into account the strategy that is always used when calculating permutations,
 * the total amount of times minus the amount of times that doesn't matches the rules, so the total amount of times that
 * two knights can be places in a board k*k, it's C(k*k, 2) because it calculates how can we place two elements in k*k places 
 * without counting the repetitions, because the elements are equals.   
 * 
 * The amount of ways that we cannot place it will depend on how the knights attack each other, according to chess, the knigts 
 * attack with an L structrue, so we count two squares straight from the knight position and the the attacked cells are 
 * on the right and left side of every edge as in the following graph where X are the attacked cells: 
 * 
 *     X # X
 *   X   #   X
 *   # # K # # 
 *   X   #   X
 *     X # X
 * 
 * Then if we have any knight on a given position, the other knight cannot be in any of those attacked cells, but we are
 * not going to foccus on the free cells, we are going to foccus on the attacked ones, because those are the permutations where
 * the two knights can't be placed, and that's the amount of permutations we have to rest from the total. 
 * In order to find that amount of permutations we have to calculate, how many positions there are in a board k*k where 
 * those knights attack each other, so if they attack in a L structure, it's the same as calculating how many L can be placed
 * in the same board. So an L is form by two cells straigts and one at the edge on the right or left side, just as the previous 
 * graph, then we see that we may have at least 3 cells straights, so according with the given k, we have two base cases, 
 * because if k = 1, we cannot even place two knights, so that would be 0 permutations, then if we have k = 2, we calculate the
 * combinations for C(2x2, 2) = C(4, 2) = 6, and we would not have any non possible permutations, because any square would be attacked
 * as we need at least 3 followed cells to create a L attacking structure, and then for k >= 3  we would have to take into account
 * the number of attacking cells. 
 * 
 * To calculate it we are gonna see the L as a rectangle, of 2x3 squares or 3x2 squres, and for a that amount of spaces we can have 
 * two positions:
 * 
 * K # #  ;   # # K          ; # K  ;  K # 
 * # # K      K # #            # #     # #
 *                             K #     # K
 * 
 * And how many of those rectangles fits on our board, well, if we put it just in the top-left corner, we can start moving it 
 * one square right, until we get to right edge of the board, so we would have horizontaly k-1 amounts of rectagnles for k >= 3
 * because we are placing it as 3x2 rectangles, so we have two columns, and then if we start moving it one square bellow, we
 * just by simetry, could also have k-2 rectangles, because now we have 3 rows instead, and the total amount of vertical rectangles
 * would be (k-1)(k-2), but fortunately we have a square board, so if we calculate the amount of horizontal rectangles that fits 
 * in the board would be the same (k-1)(k-2) so we have in total 2(k-1)(k-2) and we now that for every rectangle we have 2 possible
 * positions were they attack each other, so we can multiply that amount of rectangles by two, and that would be the total amount
 * of not aproved positions in a given board k*k.
 * 
 * So summarizing the total amount - not aprove ones : 
 * C(k*k, 2) - 4(k-1)(k-2)
 * = C(k*k, 2) - (4*k*k - 12*K + 8)
 * just for k >= 3
 * 
 * But now if we calculate the Bonomial coefficient, we would find that by its formula, calculate for k=6 or greater the first 
 * parameter would be 36 and the factorial that goes at the numerator, would be enormous, so if we see it closely, actually we 
 * would always calculate it with two as the second parameter, so the formula reduces like this
 * 
 * (k*k)!        (k*k)(k*k - 1)(k*k-2)!      (k*k)(k*K-1)
 * _____      =  _____________________   =   ___________   = C(k*k, 2)
 * 2! (k*k-2)!      2 * (k*k-2)!                   2
 * 
 */          

int main()
{
    io_boost;

    ll n; cin >> n; 

    /** @brief Binomimial coefficient C(n, k) = n! / (k!(n-k)!)  but just for C(k, 2)*/
    auto binom = [](ll n) -> ll
    {
        return (n)*(n-1) / 2;
    };

    auto calculate_permutations = [binom](ll k) -> ll
    {
        auto binom1 = binom(k*k);
        auto notGood = (4*k*k - 12*k + 8);
        return  k >= 3 ? binom1 - notGood : binom1;
    };

    for (int k = 1; k <= n; ++k)
        cout << calculate_permutations(k) << endl;

    return 0;
}