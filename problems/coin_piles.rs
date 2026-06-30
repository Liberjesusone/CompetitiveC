use std::io::{self, Read, Write};

struct Scanner { buf: std::vec::IntoIter<String> }
impl Scanner 
{
    fn new(s: &str) -> Self { Scanner { buf: s.split_ascii_whitespace().map(String::from).collect::<Vec<_>>().into_iter() } }
    fn next<T: std::str::FromStr>(&mut self) -> T { self.buf.next().unwrap().parse().ok().expect("parse") }
    fn vec<T: std::str::FromStr>(&mut self, n: usize) -> Vec<T> { (0..n).map(|_| self.next()).collect() }
}

/// # Time limit: 1.00 s
/// # Memory limit: 512 MB
///
/// # You have two coin piles containing `a` and `b` coins. On each move, you can either remove 
/// one coin from the left pile and two coins from the right pile, or two coins from the 
/// left pile and one coin from the right pile.
/// Your task is to efficiently find out if you can empty both the piles.
///
/// # Input
/// The first input line has an integer t: the number of tests.
/// After this, there are t lines, each of which has two integers a and b: the numbers of 
/// coins in the piles.
///
/// # Output
/// For each test, print "YES" if you can empty the piles and "NO" otherwise.
///
/// # Constraints
/// 1 <= t <= 10^5
/// 0 <= a, b <= 10^9
/// 
/// # Example
/// ## Input:
/// 3
/// 2 1
/// 2 2
/// 3 3
/// 
/// ## Output:
/// YES
/// NO
/// YES

/// # brief: We can consider the two piles of coins as just one pile of coins, and then for every move we take out  
/// 3 coins, so in order to empty the piles in an integer number of movements, the sum of both piles most be 
/// divisible by 3. We can see it crearly if we construct the smallest possible pile:
/// 1: a o b o        2: a o b o
///          o             o
/// 
/// after that, the only way to continue having a pair of pails that could be empty by those movemnts, is by adding
/// coins in groups of 3, the only possible way, is by adding two in any pile and one to the other pile, and if we add
/// 3 coins directly to one pile, it would be impossible to solve, so here it comes the last rule, with the brief. 
/// The smallest pile most have at leats half of the coins of the greatest pile, and the sum of them, has to be divisible by 3.
fn main()
{
    // Lee TODO stdin de golpe y crea el Scanner que parsea token a token.
    let mut input = String::new();
    io::stdin().read_to_string(&mut input).unwrap();
    let mut sc = Scanner::new(&input);

    // Salida bufferizada (rapida) en vez de println! por linea.
    let stdout = io::stdout();
    let mut out = io::BufWriter::new(stdout.lock());

    let t: usize = sc.next();          // numero de tests
    for _ in 0..t                      // _ = "no me importa el indice del bucle"
    {
        // a y b mutables porque quiza los intercambiemos. u64 = como tu 'ull'.
        let mut a: u64 = sc.next();
        let mut b: u64 = sc.next();

        // Dejar a = la pila pequena, b = la grande (como tu swap en C++).
        if a > b { std::mem::swap(&mut a, &mut b); }

        // Dos condiciones: suma divisible por 3  Y  la grande <= 2*pequena.
        // Uso 2*a >= b (forma robusta, sin division entera).
        let possible = (a + b) % 3 == 0 && 2 * a >= b;

        // En Rust el 'if' es una EXPRESION: devuelve el &str elegido.
        writeln!(out, "{}", if possible { "YES" } else { "NO" }).unwrap();
    }
}