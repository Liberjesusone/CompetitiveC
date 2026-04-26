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
 * Problema
 * 
 * - Enunciado
 * Pepito ha olvidado la contraseña de su telefono móvil. La contraseña consiste
 * en 4 dígitos del 0 al 9 (ten en cuenta que puede comenzar con el dígito 0).
 * Pepito recuerda que su contraseña tenía exactamente dos dígitos diferentes,
 * y que cada uno de estos dígitos aparecía exactamente dos veces en la contraseña.
 * Pepito también recuerda algunos dígitos que definitivamente no se usaron en la
 * contraseña.
 * Debes calcular la cantidad de secuencias diferentes de 4 dígitos que podrían
 * ser la contraseña del teléfono móvil de Pepito (es decir, estas secuencias deben
 * cumplir con todas las restricciones sobre la contraseña de Pepito).
 * 
 * @param t, n_i, a_i
 * - Entrada
 * La primera línea contiene un ́unico entero t (1 ≤ t ≤ 200), que representa el
 * número de casos de prueba.
 * La primera línea de cada caso de prueba contiene un ́unico entero n (1 ≤ n ≤ 8), 
 * que representa la cantidad de dígitos que Pepito recuerda que no fueron
 * usados en la contraseña.
 * La segunda línea contiene n enteros diferentes a_1, a_2, . . . , a_n (0 ≤ a_i ≤ 9),
 * que representan los dígitos que no se usaron en la contraseña. Los dígitos
 * a1, a2, . . . , an se dan en orden ascendente.
 * 
 * @return
 * - salida
 * Para cada caso de prueba, imprime un ́unico entero: la cantidad de diferentes
 * secuencias de 4 dígitos que cumplen las restricciones.
 * 
 * Ejemplo
 * Entrada:
 * 2
 * 8
 * 0 1 2 4 5 6 8 9
 * 1
 * 8
 * 
 * Salida:
 * 6
 * 216
 * 
 * Nota
 * Las posibles contraseñas para el primer ejemplo son: ”3377”, ”3737”, ”3773”,
 * ”7337”, ”7373”, ”7733”.
 */

ll factorial(ll n)
{
    ll mult = 1;
    for (int i = 2; i <= n; ++i)
        mult *= i;
    return mult;
}

/** @brief Binomimial coefficient C(n, k) = n! / (k!(n-k)!) 
 */
double binom(ll n, ll k)
{
    return factorial(n) / (factorial(k) * factorial(n-k));
}

/** @brief
 * In order to solve this problem we have to rely on the permutations and binomial coefficients logic 
 * 
 * The fist thing we have to calculate is the amount of ways that we can order 2 diferent numbers in 4 places
 * if we had 4 diferent numbers we would have 4P4 that is = (n)! with n=4, but as we have 2 numbers repeated two times each one
 * we actually have AABB, where A is the first number and B is the second one, so what actually happens is that for every
 * permutation A(A)B(B) we have another permutations which is a copy of the other one (A)AB(B), so in fact we have (n)! / 2
 * but that doesn't only happens with the number A, it also happens with the number B, so we would actually have (n)! / 2.2= n!/4
 * if we try this out with for n=4, thats the amount of permutations for a number of 4 digits where we use 2 digitis repeated two
 * times each one and that's equals to = (4)!/4 = 24/4 = 6, and that matches with the given hint of the problem.
 * 
 * As we doesn't change the amount of digits in the password, that would always be the amount of permutations for 2 given numbers A,B
 * but in the problem we are give a list of numbers that doesn't appear in the password, so the amount of numbers that appears in the
 * password is the totalAmountOfNumbers-amountOfRememberedNumbers, so in this caso from (0-9) we have = 10-rememberedNumbers.size
 * That amount is actually an important number becuase for every pair of two numbers we will have 6 combinations, but the amount of
 * pairs that we can get from a set of 10 numbers is actually the definition of a binomial coefficient. So we would have in total 
 * C(n, k) = n! / (k!(n-k)!) selections of k numbers that we can select from a set of n elements, as we would only select 2 elements 
 * and the amount of numbers depends on 10-rememberedNumbers.size we would calculate this formula always with k=2 and that rest as 
 * the value n.
 * The multiplications of those two factors 6*C(n, 2), it's the amount of password combinations that we can create following those rules
 *   
 * As this code only recives its data and then calculate a factorial with small numbers, would be a O(n) time complexity
 * And it does not stores any daya so it would be O(1) space complexity
 */
int main()
{
    io_boost;

    ll t, n; cin >> t; 

    for (int i = 0; i < t; ++i)
    {
        cin >> n; 
        vector<short> remembered_numbers(n);  // for every list of remembered numbers we only care about its size 
        for (int j = 0; j < n; ++j)
            cin >> remembered_numbers[j];

        // here we multiply the 6 combinations for every possible pair of numbers C(n, 2)
        cout << 6 * binom(10 - remembered_numbers.size(), 2) << endl;
    }

    return 0;
}
